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
    
    let sectionOffset: Int
    let sectionChars: Int
    
    let docOffset: Int
    let docChars: Int
    
    func percentage() -> Double {
        if docChars > 0 {
            return 100 * Double(docOffset) / Double(docChars)
        } else {
            return 0
        }
    }
}

class PlaybackController: NSObject, ObservableObject, AVSpeechSynthesizerDelegate {
    var speechSynthesizer: AVSpeechSynthesizer?
    var ttsParser: TTSParser = TTSParser()

    var playCommandHandler: Any?
    var pauseCommandHandler: Any?
    var togglePlayPauseCommandHandler: Any?
    var previousTrackCommandHandler: Any?
    var nextTrackCommandHandler: Any?
    
    @Published var language: String = "en-US"
    @Published var title: String = ""
    @Published var subtitle: String = ""
    @Published var htmlBody: String = ""
    
    var doc: TTSDocument = TTSDocument(sections: [])
    var utterances: [AVSpeechUtterance] = []
    var progressForUtterance: [AVSpeechUtterance: PlaybackProgress] = [:]
    var sectionStartDate: Date?
    
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
    
    @Published var playbackProgress: PlaybackProgress? = nil
    
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
        progressForUtterance = [:]
    }
    
    private func endSession() {
        self.doc = TTSDocument(sections: [])
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
            if self.doc.sections.count > 0 {
                startSpeech()
            } else {
                self.ttsParser.parseHTML(self.htmlBody) { doc, error in
                    if let doc = doc {
                        self.doc = doc
                        if self.doc.sections.count > 0 {
                            self.startSpeech()
                        }
                    } else {
                        print(error!)
                    }
                }
            }
        case .playing:
            break
        case .paused:
            speechSynthesizer?.continueSpeaking()
        }
    }
    
    private func startSpeech() {
        self.speechSynthesizer = AVSpeechSynthesizer()
        MPNowPlayingInfoCenter.default().nowPlayingInfo = [
            MPMediaItemPropertyTitle: title,
            MPMediaItemPropertyArtist: subtitle,
        ]
        self.speechSynthesizer?.delegate = self
        if self.doc.sections.count > 0 {
            self.startSection(0)
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
        let voice = AVSpeechSynthesisVoice(language: self.language)
        self.speechSynthesizer?.stopSpeaking(at: AVSpeechBoundary.immediate)
        
        var sectionOffset = 0
        var lineNum = 0
        let totalChars = self.doc.numChars()
        var utterances: [AVSpeechUtterance] = []
        for i in 0..<self.doc.sections.count {
            let section = self.doc.sections[i]
            
            if i >= sectionIndex {
                var sectionChars = 0
                
                for line in section.lines {
                    let utterance = AVSpeechUtterance(string: line.text)
                    utterance.voice = voice
                    utterance.rate = playbackSpeed * AVSpeechUtteranceDefaultSpeechRate
                    let progress = PlaybackProgress(section: i, sectionOffset: sectionOffset, sectionChars: sectionChars, docOffset: sectionOffset + sectionChars, docChars: totalChars)
                    if lineNum == 0 {
                        self.playbackProgress = progress
                    }
                    
                    utterances.append(utterance)
                    self.progressForUtterance[utterance] = progress
                    self.speechSynthesizer?.speak(utterance)
                    sectionChars += line.text.count
                    lineNum += 1
                }
            }
            
            sectionOffset += section.numChars()
        }
        
        self.sectionStartDate = Date()
        self.utterances = utterances.reversed()
    }
    
    func prevSection() {
        if let playbackProgress = self.playbackProgress, let sectionStartDate = self.sectionStartDate {
            let sectionElapsed = sectionStartDate.timeIntervalSinceNow
            if playbackProgress.section > 0 && sectionElapsed > -2 {
                self.startSection(playbackProgress.section - 1)
            } else {
                self.startSection(playbackProgress.section)
            }
        }
    }
    
    func nextSection() {
        if let playbackProgress = self.playbackProgress {
            if playbackProgress.section < self.doc.sections.count - 1 {
                self.startSection(playbackProgress.section + 1)
            } else {
                self.playbackState = .stopped
            }
        }
    }
    
    func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, willSpeakRangeOfSpeechString characterRange: NSRange, utterance: AVSpeechUtterance) {
        if let playbackProgress = self.playbackProgress, let newProgress = self.progressForUtterance[utterance] {
            self.playbackProgress = PlaybackProgress(
                section: newProgress.section,
                sectionOffset: newProgress.sectionOffset,
                sectionChars: newProgress.sectionChars + characterRange.lowerBound,
                docOffset: newProgress.docOffset + characterRange.lowerBound,
                docChars: newProgress.docChars
            )
            if playbackProgress.section != newProgress.section {
                self.sectionStartDate = Date()
            }
            //print("Playback progress: \(self.playbackProgress!)")
        }
    }
    
    func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didFinish utterance: AVSpeechUtterance) {
        if let nextUtterance = utterances.popLast() {
            nextUtterance.rate = playbackSpeed * AVSpeechUtteranceDefaultSpeechRate
        } else {
            self.playbackState = .stopped
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
            PlaybackProgressView(playbackProgress: playbackController.playbackProgress)
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

struct PlaybackProgressView: View {
    var playbackProgress: PlaybackProgress?

    var body: some View {
        if let progress = playbackProgress {
            ProgressView(value: progress.percentage(), total: 100.0)
        } else {
            ProgressView(value: 0, total: 100.0)
        }
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
