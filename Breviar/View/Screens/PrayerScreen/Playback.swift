//
//  Playback.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI

let playbackControlSize = CGFloat(40.0)

enum PlaybackState {
    case stopped
    case playing
    case paused
}

class PlaybackController: ObservableObject {
    @Published var playbackState: PlaybackState = .stopped
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
        HStack(spacing: 10) {
            Image("PlaybackIcon")
                .resizable()
                .aspectRatio(contentMode: .fit)
            VStack {
                HStack {
                    Text(prayer?.name ?? "Prayer Name").font(.title).multilineTextAlignment(.leading)
                    Spacer()
                }
                HStack {
                    Text(prayer?.celebration.title ?? "Celebration Title").multilineTextAlignment(.leading)
                    Spacer()
                }.padding(.vertical)
            }
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
