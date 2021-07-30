//
//  TextOptions.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI

let textOptionsWidth = CGFloat(300.0)
let textOptionsHeight = CGFloat(280.0)

struct TextOptionsView : View {
    @ObservedObject var textOptions: TextOptions
    var prayer: Prayer?
    @State var fontChooserShown = false
    
    var body: some View {
        let fontChooserTransition : AnyTransition = fontChooserShown ?
            .asymmetric(insertion: .move(edge: .trailing), removal: .move(edge: .leading)) :
            .asymmetric(insertion: .move(edge: .leading), removal: .move(edge: .trailing))
        
        if fontChooserShown {
            FontChooserList(shown: $fontChooserShown, selectedFont: $textOptions.fontName)
                .transition(fontChooserTransition)
        }
        else {
            VStack {
                TextSizeView(fontSize: $textOptions.fontSize)
                Divider()
                Button(
                    action: {
                        withAnimation {
                            fontChooserShown = true
                        }
                    },
                    label: {
                        FontChooserLabel(fontName: textOptions.fontName)
                    }
                )
                Divider()
                ColorSchemeChooserView(colorScheme: $textOptions.colorScheme)
                Divider()
                StartPlaybackButton(prayer: prayer)
            }
            .frame(width: textOptionsWidth, height: textOptionsHeight, alignment: .center)
            .transition(fontChooserTransition)
        }
    }
}

struct TextSizeView : View {
    @Binding var fontSize: Double

    var body: some View {
        HStack {
            Image(systemName: "textformat.size.smaller").padding()
            Slider(value: $fontSize, in: 60...140, step: 10)
            Image(systemName: "textformat.size.larger").padding()
        }
    }
}

struct FontChooserLabel : View {
    var fontName: FontName
    
    var body: some View {
        HStack(alignment: .center) {
            Text(S.font.S).foregroundColor(.primary)
            Spacer()
            FontLabel(font: fontName)
            Image(systemName: "chevron.right").foregroundColor(.accentColor)
        }
        .padding(.horizontal)
        .padding(.top, 5.0)
    }
}

struct FontChooserList : View {
    @Binding var shown: Bool
    @Binding var selectedFont: FontName
    
    var body: some View {
        VStack() {
            HStack {
                HStack {
                    Image(systemName: "chevron.left").foregroundColor(.accentColor)
                    Text(S.textOptions.S).foregroundColor(.accentColor)
                }.onTapGesture {
                    withAnimation {
                        shown = false
                    }
                }
                Spacer()
            }
            .padding(10.0)
            Divider().padding(.top, -7.0)
            
            List {
                ForEach(fontNames) { font in
                    Button(
                        action: {
                            withAnimation {
                                selectedFont = font
                            }
                        },
                        label: {
                            HStack {
                                FontLabel(font: font)
                                Spacer()
                                if font.name == selectedFont.name {
                                    Image(systemName: "checkmark").foregroundColor(.accentColor)
                                }
                            }
                        }
                    )
                }
            }.padding(.top, -10.0)

            Spacer()
        }
    }
}

struct FontLabel : View {
    var font: FontName
    
    var body : some View {
        Text(font.name).font(.custom(font.systemName, size: 16.0)).foregroundColor(.primary)
    }
}

enum ColorScheme: String {
    case automatic = "automatic"
    case light = "light"
    case dark = "dark"
    
    var uikitColorScheme : UIUserInterfaceStyle {
        switch self {
        case .automatic: return .unspecified
        case .light: return .light
        case .dark: return .dark
        }
    }
}

struct ColorSchemeChooserView : View {
    @Binding var colorScheme: ColorScheme
    
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
            text = Text(S.automatic.S)
        case .light:
            text = Text(S.light.S)
        case .dark:
            text = Text(S.dark.S)
        }
        
        return text.font(.system(size: 14.0))
    }
}

struct StartPlaybackButton : View {
    @EnvironmentObject var model: BreviarModel
    @State var playbackSheetShown = false
    var prayer: Prayer?

    var body: some View {
        Button(
            action: {
                playbackSheetShown = true
            },
            label: {
                Label(S.startPlayback.S, systemImage: "play.fill")
                    .frame(maxWidth: .infinity)
                    .padding(8.0)
            }
        ).sheet(isPresented: $playbackSheetShown, content: {
            PlaybackScreen(playbackSheetShown: $playbackSheetShown, prayer: prayer)
                .environmentObject(model)
        })
    }
}

struct TextOptions_Previews: PreviewProvider {
    struct TextOptionsViewContainer: View {
        @StateObject var textOptions = TextOptions()
        
        var body: some View {
            TextOptionsView(textOptions: textOptions, prayer: nil)
        }
    }
    
    static var previews: some View {
        Group {
            TextOptionsViewContainer()
                .preferredColorScheme(.light)
                .previewLayout(.fixed(width: textOptionsWidth, height: textOptionsHeight))
            
            FontChooserList(shown:.constant(true), selectedFont: .constant(fontNames[0]))
                .previewLayout(.fixed(width: textOptionsWidth, height: textOptionsHeight))
            
            TextOptionsViewContainer()
                .preferredColorScheme(.dark)
                .previewLayout(.fixed(width: textOptionsWidth, height: textOptionsHeight))
        }
    }
}
