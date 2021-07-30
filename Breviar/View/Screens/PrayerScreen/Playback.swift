//
//  Playback.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI
import AVFoundation
import MediaPlayer

let playbackControlSize = CGFloat(40.0)
let playbackText = """
    In the beginning God created the heavens and the earth.
    The earth was without form and void, and darkness was upon the face of the deep;
    and the Spirit of God was moving over the face of the waters.

    And God said, “Let there be light”; and there was light.
    And God saw that the light was good; and God separated the light from the darkness.
    God called the light Day, and the darkness he called Night.
    And there was evening and there was morning, one day.
"""

enum PlaybackState {
    case stopped
    case playing
    case paused
}

class PlaybackController: NSObject, ObservableObject, AVSpeechSynthesizerDelegate {
    var speechSynthesizer: AVSpeechSynthesizer?
    
    var playCommandHandler: Any?
    var pauseCommandHandler: Any?
    var togglePlayPauseCommandHandler: Any?
    
    @Published var title: String = ""
    @Published var subtitle: String = ""
    
    @Published var playbackState: PlaybackState = .stopped {
        willSet {
            switch newValue {
            case .stopped:
                if playbackState != .stopped {
                    endSession()
                }
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
    }
    
    private func endSession() {
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
        
        UIApplication.shared.endReceivingRemoteControlEvents()
        MPNowPlayingInfoCenter.default().nowPlayingInfo = nil
    }
    
    private func startPlayback() {
        switch playbackState {
        case .stopped:
            let voice = AVSpeechSynthesisVoice(language: "en-US")
            let utterance = AVSpeechUtterance(string: playbackText)
            utterance.voice = voice
            utterance.rate = AVSpeechUtteranceDefaultSpeechRate
            
            self.speechSynthesizer = AVSpeechSynthesizer()
            MPNowPlayingInfoCenter.default().nowPlayingInfo = [
                MPMediaItemPropertyTitle: title,
                MPMediaItemPropertyArtist: subtitle,
            ]
            self.speechSynthesizer?.delegate = self
            self.speechSynthesizer?.speak(utterance)
        case .playing:
            break
        case .paused:
            speechSynthesizer?.continueSpeaking()
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
    
    func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didFinish utterance: AVSpeechUtterance) {
        self.playbackState = .stopped
    }
}

struct PlaybackScreen: View {
    @Binding var playbackSheetShown: Bool
    var prayer: Prayer?
    
    @StateObject var playbackController: PlaybackController = PlaybackController()

    var body: some View {
        NavigationView {
            PlaybackView(playbackState: $playbackController.playbackState, prayer: prayer)
                .navigationBarItems(
                    leading: Button(
                        action: { playbackSheetShown = false },
                        label: { Text(S.back.S) }
                    )
                )
        }
        .onAppear() {
            playbackController.title = prayer?.name ?? "Prayer Name"
            playbackController.subtitle = prayer?.celebration.title ?? "Celebration Title"
            playbackController.playbackState = .playing
        }
        .onDisappear() {
            playbackController.playbackState = .stopped
        }
    }
}

struct PlaybackView: View {
    @Binding var playbackState: PlaybackState
    var prayer: Prayer?
    
    var body: some View {
        VStack {
            PlaybackTitleView(prayer: prayer)
            PlaybackControlsView(playbackState: $playbackState)
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
    
    var body: some View {
        HStack {
            Button(
                action: {
                    
                },
                label: {
                    Image(systemName: "backward.fill")
                        .resizable()
                        .frame(width: playbackControlSize, height: playbackControlSize, alignment: .center)
                })
                .disabled(playbackState != .playing)
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
                action: {
                },
                label: {
                    Image(systemName: "forward.fill")
                        .resizable()
                        .frame(width: playbackControlSize, height: playbackControlSize, alignment: .center)
                })
                .disabled(playbackState != .playing)
                .frame(maxWidth:.infinity).padding()
        }.padding()
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
        Group {
            PlaybackView(playbackState: .constant(.paused), prayer: nil)
                .preferredColorScheme(.light)
                .previewLayout(.sizeThatFits)
            
            PlaybackView(playbackState: .constant(.playing), prayer: nil)
                .preferredColorScheme(.dark)
                .previewLayout(.sizeThatFits)
        }
    }
}
