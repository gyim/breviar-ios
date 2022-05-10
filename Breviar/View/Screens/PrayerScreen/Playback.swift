//
//  Playback.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI
import AVFoundation
import MediaPlayer
import WebKit

let playbackControlSize = CGFloat(40.0)

enum PlaybackState {
    case stopped
    case playing
    case paused
}

struct PlaybackProgress {
    let section: Int
    let numSections: Int
    let line: Int
}

class PlaybackController: NSObject, ObservableObject, AVSpeechSynthesizerDelegate, WKNavigationDelegate {
    var speechSynthesizer: AVSpeechSynthesizer?
    
    var playCommandHandler: Any?
    var pauseCommandHandler: Any?
    var togglePlayPauseCommandHandler: Any?
    var previousTrackCommandHandler: Any?
    var nextTrackCommandHandler: Any?
    var webView: WKWebView = WKWebView()
    
    @Published var language: String = "en-US"
    @Published var title: String = ""
    @Published var subtitle: String = ""
    @Published var htmlBody: String = ""
    
    var ttsSections: [String] = []
    var utterances: [AVSpeechUtterance] = []
    
    override init() {
        let storedPlaybackSpeed = UserDefaults.standard.float(forKey: "speechRate")
        if storedPlaybackSpeed > 0 {
            playbackSpeed = storedPlaybackSpeed
        }
    }
    
    @Published var playbackState: PlaybackState = .stopped {
        willSet {
            switch newValue {
            case .stopped:
                endSession()
            case .playing:
                if playbackState == .stopped {
                    beginSession()
                }
                if playbackState != .playing {
                    startPlayback()
                }
            case .paused:
                if playbackState == .stopped {
                    beginSession()
                }
                if playbackState == .playing {
                    pausePlayback()
                }
            }
        }
    }

    @Published var playbackSpeed: Float = 1.0 {
        didSet {
            UserDefaults.standard.setValue(playbackSpeed, forKey: "speechRate")
        }
    }
    
    @Published var playbackProgress: PlaybackProgress? = nil {
        willSet {
            if let newProgress = newValue {
                print("Playing TTS section \(newProgress.section) of \(newProgress.numSections), line \(newProgress.line)")
                if self.playbackProgress == nil || newProgress.line == 0 {
                    startSection(newProgress.section)
                }
            }
        }
    }

    private func beginSession() {
        if playbackState != .stopped {
            return
        }
        
        let session = AVAudioSession.sharedInstance()
        do {
            try session.setCategory(.playback)
            try session.setActive(true, options: AVAudioSession.SetActiveOptions())
        } catch {
            print("Cannot start audio session")
        }
        UIApplication.shared.beginReceivingRemoteControlEvents()
        
        let commandCenter = MPRemoteCommandCenter.shared()
        playCommandHandler = commandCenter.playCommand.addTarget() { event in
            self.playbackState = .playing
            return .success
        }
        pauseCommandHandler = commandCenter.pauseCommand.addTarget() { event in
            self.playbackState = .paused
            return .success
        }
        togglePlayPauseCommandHandler = commandCenter.togglePlayPauseCommand.addTarget() { event in
            if self.playbackState == .playing {
                self.playbackState = .paused
            } else {
                self.playbackState = .playing
            }
            return .success
        }
        previousTrackCommandHandler = commandCenter.previousTrackCommand.addTarget() { event in
            self.prevSection()
            return .success
        }
        nextTrackCommandHandler = commandCenter.nextTrackCommand.addTarget() { event in
            self.nextSection()
            return .success
        }
    }
    
    private func endSession() {
        self.ttsSections = []
        self.playbackProgress = nil
        
        if playbackState == .stopped {
            return
        }
        
        // Stop playback
        if speechSynthesizer?.isSpeaking == true {
            speechSynthesizer?.stopSpeaking(at: .immediate)
        }
        speechSynthesizer = nil
        
        // Stop audio session
        do {
            let session = AVAudioSession.sharedInstance()
            try session.setActive(false, options: AVAudioSession.SetActiveOptions())
        } catch {
            print("Cannot stop audio session")
        }
        
        let commandCenter = MPRemoteCommandCenter.shared()
        if let target = playCommandHandler {
            commandCenter.playCommand.removeTarget(target)
        }
        if let target = pauseCommandHandler {
            commandCenter.pauseCommand.removeTarget(target)
        }
        if let target = togglePlayPauseCommandHandler {
            commandCenter.togglePlayPauseCommand.removeTarget(target)
        }
        if let target = previousTrackCommandHandler {
            commandCenter.previousTrackCommand.removeTarget(target)
        }
        if let target = nextTrackCommandHandler {
            commandCenter.nextTrackCommand.removeTarget(target)
        }
        
        UIApplication.shared.endReceivingRemoteControlEvents()
        MPNowPlayingInfoCenter.default().nowPlayingInfo = nil
    }
    
    private func startPlayback() {
        switch playbackState {
        case .stopped:
            if self.ttsSections != [] {
                startSpeech()
            } else {
                extractText()
            }
        case .playing:
            break
        case .paused:
            speechSynthesizer?.continueSpeaking()
        }
    }
    
    private func extractText() {
        let html = """
            <!DOCTYPE html>
            <head>
                <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>
                <link rel='stylesheet' type='text/css' href='html/breviar.css'>
                <link rel='stylesheet' type='text/css' href='html/breviar-voice-output.css'>
            </head>\n"
                <body>\(self.htmlBody)</body>
            </html>
        """
        let baseURL = URL(fileURLWithPath: Bundle.main.bundlePath)
        self.webView.navigationDelegate = self
        self.webView.loadHTMLString(html, baseURL: baseURL)
    }
    
    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        let getSpeechTextJS = """
            (function() {
                let tts_sections = document.getElementsByClassName('tts_section');
                for (let section of tts_sections) {
                    section.parentNode.insertBefore(document.createTextNode("\\n####\\n"), section);
                }
                return document.body.innerText;
            })()
        """
        self.webView.evaluateJavaScript(getSpeechTextJS) { result, error in
            guard let res = result else { print("WebKit error: \(error.debugDescription)"); return }
            guard let ttsText = res as? String else { print("WebKit returned invalid object: \(res)"); return }
            let sections = ttsText.components(separatedBy: "\n####\n")
            
            DispatchQueue.main.async {
                if self.playbackState == .playing {
                    self.ttsSections = sections
                    self.startSpeech()
                }
            }
        }
    }
    
    private func startSpeech() {
        self.speechSynthesizer = AVSpeechSynthesizer()
        MPNowPlayingInfoCenter.default().nowPlayingInfo = [
            MPMediaItemPropertyTitle: title,
            MPMediaItemPropertyArtist: subtitle,
        ]
        self.speechSynthesizer?.delegate = self
        if self.ttsSections.count > 0 {
            self.playbackProgress = PlaybackProgress(section: 0, numSections: self.ttsSections.count, line: 0)
        }
    }
    
    private func pausePlayback() {
        switch playbackState {
        case .stopped, .paused:
            break
        case .playing:
            speechSynthesizer?.pauseSpeaking(at: .immediate)
        }
    }
    
    private func startSection(_ sectionIndex: Int) {
        let text = self.ttsSections[sectionIndex]
        let voice = AVSpeechSynthesisVoice(language: self.language)
        self.speechSynthesizer?.stopSpeaking(at: AVSpeechBoundary.immediate)

        utterances = []
        for l in text.components(separatedBy: .newlines) {
            let line = l.trimmingCharacters(in: .whitespaces)
            if line.count == 0 || line == "\"" {
                continue
            }
            
            let utterance = AVSpeechUtterance(string: line)
            utterance.voice = voice
            utterance.rate = playbackSpeed * AVSpeechUtteranceDefaultSpeechRate
            
            utterances.append(utterance)
            self.speechSynthesizer?.speak(utterance)
        }
        
        if utterances.count > 0 {
            utterances.reverse()
            _ = utterances.popLast()
        }
    }
    
    func prevSection() {
        if let playbackProgress = self.playbackProgress {
            if playbackProgress.section > 0 && playbackProgress.line <= 1 {
                self.playbackProgress = PlaybackProgress(section: playbackProgress.section - 1, numSections: playbackProgress.numSections, line: 0)
            } else {
                self.playbackProgress = PlaybackProgress(section: playbackProgress.section, numSections: playbackProgress.numSections, line: 0)
            }
        }
    }
    
    func nextSection() {
        if let playbackProgress = self.playbackProgress {
            if playbackProgress.section < playbackProgress.numSections - 1 {
                self.playbackProgress = PlaybackProgress(section: playbackProgress.section + 1, numSections: playbackProgress.numSections, line: 0)
            } else {
                self.playbackState = .stopped
            }
        }
    }
    
    func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didFinish utterance: AVSpeechUtterance) {
        if let nextUtterance = utterances.popLast(), let playbackProgress = self.playbackProgress {
            self.playbackProgress = PlaybackProgress(section: playbackProgress.section, numSections: playbackProgress.numSections, line: playbackProgress.line + 1)
            nextUtterance.rate = playbackSpeed * AVSpeechUtteranceDefaultSpeechRate
        } else {
            if let playbackProgress = self.playbackProgress, playbackProgress.section < playbackProgress.numSections - 1 {
                self.playbackProgress = PlaybackProgress(section: playbackProgress.section + 1, numSections: playbackProgress.numSections, line: 0)
            }
        }
    }
}

struct PlaybackScreen: View {
    @Binding var playbackSheetShown: Bool
    @EnvironmentObject var model: BreviarModel
    var prayer: Prayer?
    
    @StateObject var playbackController: PlaybackController = PlaybackController()

    var body: some View {
        NavigationView {
            LoadingView(value: model.ttsPrayerText) { htmlBody in
                PlaybackView(playbackController: playbackController, prayer: prayer)
                    .navigationBarItems(
                        leading: Button(
                            action: { playbackSheetShown = false },
                            label: { Text(S.back.S) }
                        )
                    )
                    .onAppear() {
                        playbackController.language = model.dataSourceOptions?.language.locale.identifier ?? "en-US"
                        playbackController.title = prayer?.name ?? "Prayer Name"
                        playbackController.subtitle = prayer?.celebration.title ?? "Celebration Title"
                        playbackController.htmlBody = htmlBody
                        playbackController.playbackState = .playing
                    }
            }
        }
        .onAppear() {
            model.loadTTSPrayer(prayer!)
        }
        .onDisappear() {
            playbackController.playbackState = .stopped
        }
    }
}

struct PlaybackView: View {
    @ObservedObject var playbackController: PlaybackController
    var prayer: Prayer?
    
    var body: some View {
        VStack {
            PlaybackTitleView(prayer: prayer)
            PlaybackControlsView(
                playbackState: $playbackController.playbackState,
                playbackProgress: $playbackController.playbackProgress,
                onPrevSection: playbackController.prevSection,
                onNextSection: playbackController.nextSection
            )
            PlaybackSpeedView(playbackSpeed: $playbackController.playbackSpeed)
        }
    }
}

struct PlaybackTitleView: View {
    @EnvironmentObject var model: BreviarModel
    var prayer: Prayer?
    
    var body: some View {
        VStack {
            Image("PlaybackIcon")
                .resizable()
                .aspectRatio(contentMode: .fit)
                .padding(.vertical)
            Text(prayer?.name ?? "Prayer Name")
                .font(.largeTitle)
                .multilineTextAlignment(.center)
            Text(prayer?.celebration.title ?? "Celebration Title")
                .font(.title2)
                .multilineTextAlignment(.center)
                .padding(.vertical)
        }.padding()
    }
}

struct PlaybackControlsView: View {
    @Binding var playbackState: PlaybackState
    @Binding var playbackProgress: PlaybackProgress?
    var onPrevSection: () -> Void
    var onNextSection: () -> Void

    var body: some View {
        HStack {
            Button(
                action: onPrevSection,
                label: {
                    Image(systemName: "backward.fill")
                        .resizable()
                        .frame(width: playbackControlSize, height: playbackControlSize, alignment: .center)
                })
                .disabled(playbackProgress == nil)
                .frame(maxWidth:.infinity).padding()
            
            Button(
                action: {
                    if playbackState == .playing {
                        playbackState = .paused
                    } else {
                        playbackState = .playing
                    }
                },
                label: {
                    Image(systemName: playbackState == .playing ? "pause.fill" : "play.fill")
                        .resizable()
                        .frame(width: playbackControlSize, height: playbackControlSize, alignment: .center)
                })
                .frame(maxWidth:.infinity).padding()

            Button(
                action: onNextSection,
                label: {
                    Image(systemName: "forward.fill")
                        .resizable()
                        .frame(width: playbackControlSize, height: playbackControlSize, alignment: .center)
                })
                .disabled(playbackProgress == nil)
                .frame(maxWidth:.infinity).padding()
        }.padding()
    }
}

struct PlaybackSpeedView : View {
    @Binding var playbackSpeed: Float

    var body: some View {
        let minValue = AVSpeechUtteranceMinimumSpeechRate / AVSpeechUtteranceDefaultSpeechRate
        let maxValue = AVSpeechUtteranceMaximumSpeechRate / AVSpeechUtteranceDefaultSpeechRate
        
        HStack {
            Text("0.5×").frame(minWidth: 50).padding()
            Slider(value: $playbackSpeed, in: minValue...maxValue) { changed in }
            Text("2×").frame(minWidth: 50).padding()
        }
        
    }
}

struct Playback_Previews: PreviewProvider {
    struct TextOptionsViewContainer: View {
        @StateObject var textOptions = TextOptions()
        
        var body: some View {
            TextOptionsView(textOptions: textOptions)
        }
    }
    
    static var previews: some View {
        let playbackController = PlaybackController()
        
        Group {
            PlaybackView(playbackController: playbackController, prayer: nil)
                .preferredColorScheme(.light)
                .previewLayout(.sizeThatFits)
            
            PlaybackView(playbackController: playbackController, prayer: nil)
                .preferredColorScheme(.dark)
                .previewLayout(.sizeThatFits)
        }
    }
}
