//
//  TextOptions.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI

struct TextOptionsView : View {
    @ObservedObject var textOptions: TextOptions
    
    var body: some View {
        VStack {
            TextSizeView(fontSize: $textOptions.fontSize)
            Divider()
            ColorSchemeChooserView(colorScheme: $textOptions.colorScheme)
        }.frame(width: 300, height: 180, alignment: .center)
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

enum ColorScheme {
    case automatic
    case light
    case dark
    
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
            text = Text("Automatic")
        case .light:
            text = Text("Light")
        case .dark:
            text = Text("Dark")
        }
        
        return text
    }
}

struct TextOptions_Previews: PreviewProvider {
    struct TextOptionsViewContainer: View {
        @StateObject var textOptions = TextOptions()
        
        var body: some View {
            TextOptionsView(textOptions: textOptions)
        }
    }
    
    static var previews: some View {
        Group {
            TextOptionsViewContainer()
                .preferredColorScheme(.light)
                .previewLayout(.fixed(width: 300.0, height: 180.0))
            
            TextOptionsViewContainer()
                .preferredColorScheme(.dark)
                .previewLayout(.fixed(width: 300.0, height: 180.0))
        }
    }
}
