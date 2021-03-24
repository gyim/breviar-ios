//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

struct PrayerScreen: View {
    @State var isPopoverPresented = false
    var prayerName: String
    var content: LoadingState<String> = .idle
    
    var body: some View {
        PrayerScreenContent(content: content)
            .navigationTitle(prayerName)
            .navigationBarTitleDisplayMode(.inline)
            .toolbar(content: {
                Button(action: {
                    isPopoverPresented.toggle()
                }, label: {Label("", systemImage:"textformat.size")})
                .popover(isPresented: $isPopoverPresented) {
                    TextOptionsView()
                }
            })
    }
}

struct PrayerScreenContent: View {
    var content: LoadingState<String> = .idle
    
    var body: some View {
        switch content {
        case .idle, .loading:
            Text("Loading...")
        case .loaded(let text):
            WebView(text: text)
        case .failed(let error):
            Text(error.localizedDescription)
        }
    }
}

class PrayerView : WKWebView {
}

struct WebView : UIViewRepresentable {
    var text: String
    
    func makeUIView(context: Context) -> WKWebView {
        return PrayerView()
    }
    
    func updateUIView(_ uiView: WKWebView, context: Context) {
        let baseURL = URL(string: "https://lh.kbs.sk/cgi-bin")
        uiView.loadHTMLString(text, baseURL: baseURL)
    }
}

struct TextOptionsView : View {
    
    var body: some View {
        VStack {
            TextSizeView()
            Divider()
            ColorSchemeChooserView()
            Divider()
            PlaybackView()
        }.frame(width: 300, height: 300, alignment: .center)
    }
}

struct TextSizeView : View {
    @State var fontSize = 5.0

    var body: some View {
        HStack {
            Image(systemName: "textformat.size.smaller").padding()
            Slider(value: $fontSize, in: 1...10, step: 1.0)
            Image(systemName: "textformat.size.larger").padding()
        }
    }
}

enum ColorScheme {
    case automatic
    case light
    case dark
}

struct ColorSchemeChooserView : View {
    @State var colorScheme = ColorScheme.automatic
    
    var body: some View {
        HStack {
            ColorSchemeButton(colorScheme: .automatic, selected: colorScheme == .automatic) {
                colorScheme = .automatic
            }
            ColorSchemeButton(colorScheme: .light, selected: colorScheme == .light) {
                colorScheme = .light
            }
            ColorSchemeButton(colorScheme: .dark, selected: colorScheme == .dark) {
                colorScheme = .dark
            }
        }.padding()
    }
}

struct ColorSchemeButton : View {
    @Environment(\.colorScheme) var systemColorScheme
    
    var colorScheme: ColorScheme
    var selected: Bool
    var action: () -> Void
    
    var body: some View {
        VStack {
            circleView().frame(width: 40, height: 40, alignment: .center)
            labelView().frame(maxWidth:.infinity).foregroundColor(selected ? .accentColor : .primary)
        }.onTapGesture {
            withAnimation {
                action()
            }
        }
    }
    
    func circleView() -> some View {
        switch colorScheme {
        case .automatic:
            return Circle()
                .strokeBorder(selected ? Color.accentColor : Color.secondary, lineWidth: 3.0)
                .background(Circle().foregroundColor(.clear))
        case .light:
            return Circle()
                .strokeBorder(selected ? Color.accentColor : Color.secondary, lineWidth: 3.0)
                .background(Circle().foregroundColor(.white))
        case .dark:
            return Circle()
                .strokeBorder(selected ? Color.accentColor : Color.secondary, lineWidth: 3.0)
                .background(Circle().foregroundColor(.black))
        }
    }
    
    func labelView() -> some View {
        var text : Text
        
        switch colorScheme {
        case .automatic:
            text = Text("Automatic")
        case .light:
            text = Text("Light")
        case .dark:
            text = Text("Dark")
        }
        
        return text
    }
}

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

struct PrayerScreen_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            NavigationView {
                PrayerScreen(prayerName: "Morning Prayer", content: .loaded("<b>Hello world</b>"))
            }.navigationViewStyle(StackNavigationViewStyle())
            
            TextOptionsView()
                .preferredColorScheme(.light)
                .previewLayout(.fixed(width: 300.0, height: 300.0))
            
            TextOptionsView()
                .preferredColorScheme(.dark)
                .previewLayout(.fixed(width: 300.0, height: 300.0))
        }
    }
}
