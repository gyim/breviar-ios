//
//  Playback.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI

struct PlaybackView: View {
    @State var active = false
    
    var body: some View {
        HStack {
            Button(action: {}, label: {
                Image(systemName: "backward.fill").resizable().frame(width: 30, height: 30, alignment: .center)
            }).disabled(!active).frame(maxWidth:.infinity).padding()
            Button(action: {active.toggle()}, label: {
                Image(systemName: active ? "pause.fill" : "play.fill").resizable().frame(width: 30, height: 30, alignment: .center)
            }).frame(maxWidth:.infinity).padding()
            Button(action: {}, label: {
                Image(systemName: "forward.fill").resizable().frame(width: 30, height: 30, alignment: .center)
            }).disabled(!active).frame(maxWidth:.infinity).padding()
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
            PlaybackView()
                .preferredColorScheme(.light)
                .previewLayout(.sizeThatFits)
            
            PlaybackView()
                .preferredColorScheme(.dark)
                .previewLayout(.sizeThatFits)
        }
    }
}
