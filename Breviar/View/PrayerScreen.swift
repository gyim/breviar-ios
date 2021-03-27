//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

// MARK: Prayer Screen Controller

struct PrayerScreenControllerRepresentable: UIViewControllerRepresentable {
    var prayer: Prayer    
    @ObservedObject var textOptions: TextOptions
    @Binding var textOptionsShown: Bool

    class Coordinator: NSObject, UIPopoverPresentationControllerDelegate {
        var parent: PrayerScreenControllerRepresentable
        var webView: WKWebView
        var textOptionsPopoverShown = false
        
        init(_ parent: PrayerScreenControllerRepresentable) {
            self.parent = parent
            self.webView = WKWebView()
            self.webView.loadHTMLString("Hello World", baseURL: nil)
        }
        
        func showTextOptions(controller: UIViewController, show: Bool) {
            if show && !textOptionsPopoverShown {
                textOptionsPopoverShown = true
                
                // Calculate source rectangle
                //
                // NOTE: it would be easier to set popover.popoverPresentationController?.barButtonItem,
                // but then the popover moves away when its data is changed. This is probably a SwiftUI bug.
                let window = UIApplication.shared.windows[0]
                let sourceView = controller.navigationController!.navigationBar
                let r = sourceView.bounds
                let w = r.height // button width = navbar height
                let sourceRect = CGRect(x: r.origin.x + r.width - w - window.safeAreaInsets.right, y: r.origin.y, width: w, height: r.height)
                
                // Create popover
                let popover = UIHostingController(rootView: TextOptionsView(textOptions: self.parent.textOptions))
                popover.preferredContentSize = popover.sizeThatFits(in:CGSize(width:300, height:300))
                popover.modalPresentationStyle = .popover
                popover.popoverPresentationController?.sourceView = sourceView
                popover.popoverPresentationController?.sourceRect = sourceRect
                popover.popoverPresentationController?.delegate = self
                controller.present(popover, animated: true)
            }
        }

        @objc func adaptivePresentationStyle(for controller: UIPresentationController, traitCollection: UITraitCollection) -> UIModalPresentationStyle {
            return .none // Force popover style on iPhone
        }
        
        @objc func popoverPresentationControllerDidDismissPopover(_ popoverPresentationController: UIPopoverPresentationController) {
            self.textOptionsPopoverShown = false
            self.parent.textOptionsShown = false
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(self)
    }
    
    func makeUIViewController(context: Context) -> some UIViewController {
        let controller = UIViewController()
        controller.view = context.coordinator.webView
        return controller
    }
    
    func updateUIViewController(_ controller: UIViewControllerType, context: Context) {
        context.coordinator.showTextOptions(controller: controller, show: textOptionsShown)
    }
}

struct PrayerScreen: View {
    @State var textOptionsShown = false
    @StateObject var textOptions = TextOptions()
    var prayer: Prayer
    
    var body: some View {
        PrayerScreenControllerRepresentable(prayer:prayer, textOptions: textOptions, textOptionsShown: $textOptionsShown)
            .navigationTitle(prayer.name)
            .navigationBarTitleDisplayMode(.inline)
            .toolbar(content: {
                Button(action: {
                    textOptionsShown = true
                }, label: {Label("", systemImage:"textformat.size")})
            })
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

// MARK:- Text Options Popup

class TextOptions: ObservableObject {
    @Published var fontSize = 5.0
    @Published var colorScheme = ColorScheme.automatic
}

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

// MARK:- Playback View

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

            PlaybackView()
                .preferredColorScheme(.light)
                .previewLayout(.sizeThatFits)
            
            PlaybackView()
                .preferredColorScheme(.dark)
                .previewLayout(.sizeThatFits)
        }
    }
}
