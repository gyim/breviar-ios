//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

struct PrayerScreen: View {
    @EnvironmentObject var model: BreviarModel
    @State var textOptionsShown = false
    var prayer: Prayer
    var prayerText: LoadingState<String>
    @Binding var textOptions: TextOptions
    @State var navbarHidden = false

    var body: some View {
        InlinePopoverPresenter( popover: { TextOptionsView(textOptions: textOptions) }, isPresented: $textOptionsShown) {
            LoadingView(value: prayerText, loadedBody: { text in
                NavigationBarToggler(navigationBarHidden: $navbarHidden) {
                    PrayerView(text: text, textOptions: textOptions)
                        .ignoresSafeArea()
                        .onTapGesture() {
                            withAnimation {
                                navbarHidden.toggle()
                            }
                        }
                }.ignoresSafeArea()
            }).ignoresSafeArea()
        }
        .ignoresSafeArea()
        .navigationTitle(prayer.name)
        .navigationBarTitleDisplayMode(.inline)
        .navigationBarHidden(navbarHidden)
        .statusBar(hidden: navbarHidden)
        .toolbar(content: {
            Button(action: {
                textOptionsShown = true
            }, label: {Label("", systemImage:"textformat.size")})
        })
        .onAppear() {
            model.loadPrayer(prayer)
        }
    }
}

struct PrayerView : UIViewRepresentable {
    var text: String
    var textOptions: TextOptions
    
    class PrayerWebView : WKWebView {
        override var safeAreaInsets: UIEdgeInsets {
            return UIEdgeInsets(top: 0, left: 0, bottom: 0, right: 0)
        }
    }
    
    class Coordinator {
        var webView: WKWebView = PrayerWebView()
        var prevText: String = ""
        var prevFontSize: Double = 100.0
        var topPadding: CGFloat = 0
        var bottomPadding: CGFloat = 0
        
        init() {
            // This view is not updated if TextOptions is changed in the popover, so we rely on NotificationCenter instead
            NotificationCenter.default.addObserver(self, selector: #selector(onTextOptionsChanged(_:)), name: TextOptions.notificationName, object: nil)
            
            // Top padding: safe area inset (notch + statusbar) + navbar height
            topPadding += 50.0 // navbar height
            bottomPadding = 0.0
            if let safeAreaInsets = UIApplication.shared.windows[0].rootViewController?.view.safeAreaInsets {
                topPadding += safeAreaInsets.top
                bottomPadding += safeAreaInsets.bottom
            }
        }
        
        deinit {
            NotificationCenter.default.removeObserver(self)
        }
        
        @objc func onTextOptionsChanged(_ notification: Notification) {
            if let textOptions = notification.object as? TextOptions {
                setPrayerText(text: prevText, fontSize: textOptions.fontSize)
            }
        }
        
        func setPrayerText(text: String, fontSize: Double) {
            if text != prevText {
                prevText = text
                prevFontSize = fontSize
                
                let modifiedText = getModifiedText(text: text, fontSize: fontSize)
                let baseURL = URL(string: "https://lh.kbs.sk/cgi-bin")
                self.webView.loadHTMLString(modifiedText, baseURL: baseURL)
            }
            if fontSize != prevFontSize {
                prevFontSize = fontSize
                
                self.webView.evaluateJavaScript("setFontSize(\(fontSize))") { (_, error) in
                    if error != nil {
                        print("Error setting font size: \(error.debugDescription)")
                    }
                }
            }
        }
        
        func getModifiedText(text: String, fontSize: Double) -> String {
            let body = getBody(text)
            return """
                <head>
                    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
                    <meta name="viewport" content="width=device-width, user-scalable=yes, initial-scale=1.0" />
                    <link rel="stylesheet" type="text/css" href="/breviar.css" />
                    <style type="text/css">
                        @import url("/breviar-normal-font.css") screen;
                        @import url("/breviar-invert-colors.css") screen and (prefers-color-scheme: dark);
                        body { padding: \(topPadding)px 0 \(bottomPadding)px; }
                    </style>
                    <script type="text/javascript">
                        function setFontSize(fontSize) {
                            document.body.style.webkitTextSizeAdjust = `${fontSize}%`;
                        }
                        function initPrayer() {
                            setFontSize(\(fontSize));
                        }
                    </script>
                </head>
                <body onload="initPrayer()">\(body)</body>
            """
        }
        
        func getBody(_ html: String) -> String {
            // Find body start
            var body: String.SubSequence = html[html.startIndex...]
            if let r = html.range(of: "<body") {
                let b = html[r.upperBound...]
                if let r = b.range(of:">") {
                    body = b[r.upperBound...].dropFirst()
                }
            }
            
            // Find body end
            if let r = body.range(of: "</body") {
                body = body[body.startIndex..<r.lowerBound]
            }
            
            // Replace ` characters with '
            return String(body.replacingOccurrences(of: "`", with: "'"))
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator()
    }
    
    func makeUIView(context: Context) -> WKWebView {
        return context.coordinator.webView
    }
    
    func updateUIView(_ uiView: WKWebView, context: Context) {
        context.coordinator.setPrayerText(text: text, fontSize: textOptions.fontSize)
    }
}
