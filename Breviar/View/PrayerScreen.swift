//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

// MARK: Prayer Screen Controller

class PrayerScreenController: UIViewController, UIPopoverPresentationControllerDelegate {
    var webView: WKWebView?
    var textOptionsPopoverDismissed: (() -> Void)?

    override func viewDidLoad() {
        super.viewDidLoad()

        // Configure web view
        self.webView = WKWebView()
        self.view = self.webView
        self.webView?.loadHTMLString("Hello World", baseURL: nil)
    }
    
    func showTextOptions(show: Bool, dismissed: @escaping () -> Void) {
        if show && self.presentedViewController == nil {
            // Find navigation item that triggered the popover
            guard let navItems = self.navigationController?.navigationBar.items else {
                print("No navigation items")
                return
            }
            if navItems.count < 1 {
                print("No navigation items")
                return
            }
            let navItem = navItems[navItems.count-1]
            
            // Create popover
            let popover = UIHostingController(rootView: TextOptionsView())
            popover.preferredContentSize = popover.sizeThatFits(in:CGSize(width:300, height:300))
            popover.modalPresentationStyle = .popover
            popover.popoverPresentationController?.barButtonItem = navItem.rightBarButtonItem
            popover.popoverPresentationController?.delegate = self
            self.textOptionsPopoverDismissed = dismissed
            self.present(popover, animated: true)
        }
    }
    
    @objc func adaptivePresentationStyle(for controller: UIPresentationController, traitCollection: UITraitCollection) -> UIModalPresentationStyle {
        return .none // Force popover style on iPhone
    }
    
    @objc func popoverPresentationControllerDidDismissPopover(_ popoverPresentationController: UIPopoverPresentationController) {
        if let dismissed = self.textOptionsPopoverDismissed {
            dismissed()
            self.textOptionsPopoverDismissed = nil
        }
    }
}

struct PrayerScreenControllerRepresentable: UIViewControllerRepresentable {
    var prayer: Prayer
    @Binding var textOptionsShown: Bool
    
    func makeUIViewController(context: Context) -> some UIViewController {
        return PrayerScreenController()
    }
    
    func updateUIViewController(_ c: UIViewControllerType, context: Context) {
        guard let controller = c as? PrayerScreenController else { return }
        controller.showTextOptions(show: textOptionsShown) {
            textOptionsShown = false
        }
    }
}

struct PrayerScreen: View {
    @State var textOptionsShown = false
    var prayer: Prayer
    
    var body: some View {
        PrayerScreenControllerRepresentable(prayer:prayer, textOptionsShown: $textOptionsShown)
            .navigationTitle(prayer.name)
            .navigationBarTitleDisplayMode(.inline)
            .toolbar(content: {
                Button(action: {
                    textOptionsShown = true
                }, label: {Label("", systemImage:"textformat.size")})
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

// MARK:- Text Options Popup

struct TextOptionsView : View {
    
    var body: some View {
        VStack {
            TextSizeView()
            Divider()
            ColorSchemeChooserView()
        }.frame(width: 300, height: 180, alignment: .center)
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
    static var previews: some View {
        Group {
            TextOptionsView()
                .preferredColorScheme(.light)
                .previewLayout(.fixed(width: 300.0, height: 180.0))
            
            TextOptionsView()
                .preferredColorScheme(.dark)
                .previewLayout(.fixed(width: 300.0, height: 180.0))

            PlaybackView()
                .preferredColorScheme(.light)
                .previewLayout(.fixed(width: 300.0, height: 300.0))
            
            PlaybackView()
                .preferredColorScheme(.dark)
                .previewLayout(.fixed(width: 300.0, height: 300.0))
        }
    }
}
