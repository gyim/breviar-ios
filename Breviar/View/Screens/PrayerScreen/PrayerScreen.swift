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
    @Environment(\.presentationMode) var presentationMode
    @State var textOptionsShown = false
    @State var playbackSheetShown = false
    var prayer: Prayer
    @Binding var prayerText: LoadingState<String>
    @Binding var textOptions: TextOptions
    @State var navbarHidden = false
    @State private var needsReload = false
    @StateObject private var autoLockManager = AutoLockManager()
    
    var body: some View {
        InlinePopoverPresenter( popover: { TextOptionsView(textOptions: textOptions, prayer: prayer).environmentObject(model) }, isPresented: $textOptionsShown) {
            LoadingView(value: prayerText, loadedBody: { text in
                NavigationBarToggler(navigationBarHidden: $navbarHidden) {
                    PrayerView(text: text, textOptions: textOptions, needsReload: $needsReload)
                        .onTapEvent() {
                            if model.prayerScreenSettings.fullscreenMode == .singleTap {
                                withAnimation {
                                    navbarHidden.toggle()
                                }
                            }
                        }
                        .onDoubleTapEvent() {
                            if model.prayerScreenSettings.fullscreenMode == .doubleTap {
                                withAnimation {
                                    navbarHidden.toggle()
                                }
                            }
                        }
                        .onLinkEvent() { url in
                            model.handlePrayerLink(prayer: prayer, url: url)
                        }
                        .ignoresSafeArea()
                }.ignoresSafeArea()
            }).ignoresSafeArea()
        }
        .ignoresSafeArea()
        .navigationTitle(prayer.name)
        .navigationBarTitleDisplayMode(.inline)
        .navigationBarHidden(navbarHidden)
        .statusBar(hidden: navbarHidden)
        .toolbar(content: {
            HStack {
                Button(action: {
                    playbackSheetShown = true
                }, label: {Label("", systemImage:"play.fill")})
                
                Button(action: {
                    textOptionsShown = true
                }, label: {Label("", systemImage:"textformat.size")})
            }
        })
        .sheet(isPresented: $playbackSheetShown, content: {
            PlaybackScreen(playbackSheetShown: $playbackSheetShown, prayer: prayer)
                .environmentObject(model)
        })
        .onAppear() {
            model.loadPrayer(prayer)
            autoLockManager.disableAutoLock()
        }
        .onDisappear() {
            model.unloadPrayer()
            autoLockManager.enableAutoLock()
        }
        .onChange(of: needsReload) { needsReload in
            if needsReload {
                print("PrayerScreen: Reloading prayer due to WebView state loss")
                model.loadPrayer(prayer)
                self.needsReload = false
            }
        }
        .onReceive(NotificationCenter.default.publisher(for: UIApplication.willEnterForegroundNotification)) { _ in
            // Check if prayer text needs to be reloaded
            if case .loaded = prayerText {
                print("PrayerScreen: App entering foreground, checking WebView state")
                // The WebView will detect if it needs reload
            }
        }
        .onReceive(model.$pendingNavigation) { pending in
            if let pending = pending, case .prayer(let targetPrayer) = pending {
                // If we're navigating to a different prayer, dismiss this screen
                if targetPrayer.type != prayer.type || targetPrayer.day != prayer.day {
                    presentationMode.wrappedValue.dismiss()
                }
            }
        }
    }
}

struct PrayerView : UIViewRepresentable {
    var text: String
    var textOptions: TextOptions
    @Binding var needsReload: Bool
    var tapHandler: (() -> ())?
    var doubleTapHandler: (() -> ())?
    var linkHandler: ((URL) -> ())?
    
    class PrayerWebView : WKWebView {
        override var safeAreaInsets: UIEdgeInsets {
            return UIEdgeInsets(top: 0, left: super.safeAreaInsets.left, bottom: 0, right: super.safeAreaInsets.right)
        }
    }
    
    class Coordinator : NSObject, WKScriptMessageHandler, WKNavigationDelegate {
        var parent: PrayerView
        var webView = PrayerWebView()
        var prevText: String = ""
        var prevFontName: String = fontNames[0].systemName
        var prevFontSize: Double = 100.0
        var prevIsBold: Bool = false
        var topPadding: CGFloat = 0
        var bottomPadding: CGFloat = 0
        var isWebViewReady = false
        
        init(parent: PrayerView) {
            self.parent = parent
            super.init()
            
            // This view is not updated if TextOptions is changed in the popover, so we rely on NotificationCenter instead
            NotificationCenter.default.addObserver(self, selector: #selector(onTextOptionsChanged(_:)), name: TextOptions.notificationName, object: nil)
            
            // Listen for app lifecycle events
            NotificationCenter.default.addObserver(self, selector: #selector(appWillEnterForeground), name: UIApplication.willEnterForegroundNotification, object: nil)
            
            // Top padding: safe area inset (notch + statusbar) + navbar height
            topPadding = 50.0 // navbar height
            bottomPadding = 0.0
            if let safeAreaInsets = UIApplication.shared.windows[0].rootViewController?.view.safeAreaInsets {
                topPadding += safeAreaInsets.top
                bottomPadding += safeAreaInsets.bottom
            }
            
            // Setup web view
            let contentController = WKUserContentController()
            contentController.add(self, name: "onTapEvent")
            contentController.add(self, name: "onDoubleTapEvent")
            contentController.add(self, name: "onLinkEvent")
            contentController.add(self, name: "checkAlive")
            let webViewConfig = WKWebViewConfiguration()
            webViewConfig.userContentController = contentController
            webView = PrayerWebView(frame: CGRect(), configuration: webViewConfig)
            webView.allowsLinkPreview = false
            webView.isOpaque = false
            webView.configuration.defaultWebpagePreferences.preferredContentMode = .mobile
            webView.navigationDelegate = self
        }
        
        deinit {
            NotificationCenter.default.removeObserver(self)
        }
        
        @objc func onTextOptionsChanged(_ notification: Notification) {
            if let textOptions = notification.object as? TextOptions {
                setPrayerText(text: prevText, fontName: textOptions.fontName.systemName, fontSize: textOptions.fontSize, isBold: textOptions.isBold)
            }
        }
        
        @objc func appWillEnterForeground() {
            print("PrayerView: App will enter foreground, checking WebView content")
            checkWebViewContent()
        }
        
        func checkWebViewContent() {
            // Check if WebView content is still valid
            webView.evaluateJavaScript("document.body ? document.body.innerHTML.length : 0") { [weak self] (result, error) in
                guard let self = self else { return }
                
                if let error = error {
                    print("PrayerView: Error checking WebView content: \(error)")
                    self.handleWebViewContentLoss()
                    return
                }
                
                if let length = result as? Int {
                    print("PrayerView: WebView content length: \(length)")
                    if length == 0 && !self.prevText.isEmpty {
                        print("PrayerView: WebView content lost, triggering reload")
                        self.handleWebViewContentLoss()
                    }
                } else {
                    print("PrayerView: Unexpected WebView check result")
                    self.handleWebViewContentLoss()
                }
            }
        }
        
        func handleWebViewContentLoss() {
            // Reset state and trigger reload
            isWebViewReady = false
            prevText = ""
            DispatchQueue.main.async {
                self.parent.needsReload = true
            }
        }
        
        func setPrayerText(text: String, fontName: String, fontSize: Double, isBold: Bool) {
            if text != prevText {
                let modifiedText = getModifiedText(text: text, fontName: fontName, fontSize: fontSize, isBold: isBold)
                if prevText == "" || !isWebViewReady {
                    let baseURL = URL(fileURLWithPath: Bundle.main.bundlePath)
                    self.webView.loadHTMLString(modifiedText, baseURL: baseURL)
                } else {
                    self.webView.evaluateJavaScript("document.documentElement.innerHTML = `\(modifiedText)`; initPrayer(); setFont('\(fontName)', \(fontSize), \(isBold));") { [weak self] (_, error) in
                        if let error = error {
                            print("Error reloading document: \(error.localizedDescription)")
                            // If JavaScript evaluation fails, reload the WebView
                            self?.isWebViewReady = false
                            let baseURL = URL(fileURLWithPath: Bundle.main.bundlePath)
                            self?.webView.loadHTMLString(modifiedText, baseURL: baseURL)
                        }
                    }
                }
                
                prevText = text
                prevFontSize = fontSize
                prevIsBold = isBold
            }
            if fontName != prevFontName || fontSize != prevFontSize || isBold != prevIsBold {
                prevFontName = fontName
                prevFontSize = fontSize
                prevIsBold = isBold
                
                if isWebViewReady {
                    self.webView.evaluateJavaScript("setFont('\(fontName)', \(fontSize), \(isBold))") { (_, error) in
                        if error != nil {
                            print("Error setting font size: \(error.debugDescription)")
                        }
                    }
                }
            }
        }
        
        func getModifiedText(text: String, fontName: String, fontSize: Double, isBold: Bool) -> String {
            return """
                <head>
                    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
                    <meta name="viewport" content="width=device-width, user-scalable=yes, initial-scale=1.0" />
                    <link rel="stylesheet" type="text/css" href="html/breviar.css" />
                    <link rel="stylesheet" type="text/css" href="html/breviar-normal-font.css" />
                    <style type="text/css">
                        @import url("html/breviar-invert-colors.css") screen and (prefers-color-scheme: dark);
                        body { padding: \(topPadding)px 0 \(bottomPadding)px; }
                    </style>
                    <script type="text/javascript">
                        window.isAlive = true;
                        function setFont(fontName, fontSize, isBold) {
                            document.body.style.fontFamily = fontName;
                            document.body.style.webkitTextSizeAdjust = fontSize + '%';
                            document.styleSheets.item(1).disabled = isBold;
                        }
                        function setupTapGesture() {
                            let tapCount = 0;
                            let tapTimeout;
                            
                            document.body.onclick = function() {
                                tapCount++;
                                
                                clearTimeout(tapTimeout);
                                tapTimeout = setTimeout(function() {
                                    if (tapCount === 1) {
                                        window.webkit.messageHandlers.onTapEvent.postMessage({});
                                    } else if (tapCount === 2) {
                                        window.webkit.messageHandlers.onDoubleTapEvent.postMessage({});
                                    }
                                    tapCount = 0;
                                }, 300);
                            }
                        }
                        function setupLinks() {
                            for (let link of document.getElementsByTagName('a')) {
                                link.onclick = function(e) {
                                    window.webkit.messageHandlers.onLinkEvent.postMessage(link.href);
                                    e.stopPropagation();
                                    return false;
                                }
                            }
                        }
                        function initPrayer() {
                            setupTapGesture();
                            setupLinks();
                            setFont('\(fontName)', \(fontSize), \(isBold));
                            window.webkit.messageHandlers.checkAlive.postMessage(true);
                        }
                    </script>
                </head>
                <body onload="initPrayer()">\(text)</body>
            """
        }
        
        // WKNavigationDelegate
        func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
            print("PrayerView: WebView did finish loading")
            isWebViewReady = true
        }
        
        func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
            print("PrayerView: WebView navigation failed: \(error)")
            isWebViewReady = false
        }
        
        // WKScriptMessageHandler
        func userContentController(_ userContentController: WKUserContentController, didReceive message: WKScriptMessage) {
            switch message.name {
            case "onTapEvent":
                if let handler = parent.tapHandler {
                    handler()
                }
            case "onDoubleTapEvent":
                if let handler = parent.doubleTapHandler {
                    handler()
                }
            case "onLinkEvent":
                if let handler = parent.linkHandler, let u = message.body as? String, let url = URL(string:u) {
                    handler(url)
                }
            case "checkAlive":
                print("PrayerView: WebView JavaScript context is alive")
            default:
                break
            }
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(parent: self)
    }
    
    func makeUIView(context: Context) -> WKWebView {
        return context.coordinator.webView
    }
    
    func updateUIView(_ uiView: WKWebView, context: Context) {
        context.coordinator.setPrayerText(text: text, fontName: textOptions.fontName.systemName, fontSize: textOptions.fontSize, isBold: textOptions.isBold)
    }

    func onTapEvent(_ newHandler: @escaping () -> ()) -> PrayerView {
        var view = self
        view.tapHandler = newHandler
        return view
    }

    func onDoubleTapEvent(_ newHandler: @escaping () -> ()) -> PrayerView {
        var view = self
        view.doubleTapHandler = newHandler
        return view
    }

    func onLinkEvent(_ newHandler: @escaping (_ url: URL) -> ()) -> PrayerView {
        var view = self
        view.linkHandler = newHandler
        return view
    }
}

struct AboutScreen: View {
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        LoadingView(value: model.aboutPage) { text in
            PrayerView(text: text, textOptions: model.textOptions, needsReload: .constant(false))
                .onLinkEvent() { url in
                    UIApplication.shared.open(url)
                }
        }
        .navigationTitle(S.aboutBreviary.S)
        .navigationBarTitleDisplayMode(.inline)
        .ignoresSafeArea()
        .onAppear() {
            model.loadAboutPage()
        }
    }
    
}
