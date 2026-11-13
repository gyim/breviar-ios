//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit
import SafariServices

struct IdentifiableURL: Identifiable {
    var url: URL

    var id: String {
        return url.absoluteString
    }
}

struct SafariView: UIViewControllerRepresentable {
    var url: URL

    func makeUIViewController(context: Context) -> SFSafariViewController {
        return SFSafariViewController(url: url)
    }

    func updateUIViewController(_ controller: SFSafariViewController, context: Context) {
    }
}

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
    var shared = false
    @State private var sharingLink: IdentifiableURL? = nil
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
                            if shared { model.handleSharedPrayerLink(url) }
                            else { model.handlePrayerLink(prayer: prayer, url: url) }
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
                    if case .loaded(let html) = prayerText, let url = model.linkToShare(in: html) {
                        sharingLink = IdentifiableURL(url: url)
                    } else { model.sharingError = S.sharePrayerUnavailable.S }
                }, label: { Label(S.sharePrayer.S, systemImage: "qrcode") })
                Button(action: {
                    playbackSheetShown = true
                }, label: {Label("", systemImage:"play.fill")})
                
                Button(action: {
                    textOptionsShown = true
                }, label: {Label("", systemImage:"textformat.size")})
            }
        })
        .sheet(isPresented: $playbackSheetShown, content: {
            PlaybackScreen(playbackSheetShown: $playbackSheetShown, prayer: prayer, shared: shared)
                .environmentObject(model)
        })
        .sheet(item: $sharingLink) { link in PrayerShareSheet(url: link.url) }
        .sheet(item: shared ? $model.sharedExternalLink : $model.externalLink, content: { link in
            SafariView(url: link.url)
                .ignoresSafeArea()
        })
        .onScreenshotAction { action in
            switch action {
            case .textOptions:
                textOptionsShown = true
                ScreenshotMode.signalReadyAfterAnimation()
            case .playback:
                playbackSheetShown = true
                ScreenshotMode.signalReadyAfterAnimation(delay: 2.0)
            case .fullscreen:
                navbarHidden = true
                ScreenshotMode.signalReadyAfterAnimation()
            default:
                break
            }
        }
        .onAppear() {
            if shared {
                if case .idle = prayerText { model.loadSharedPrayer() }
            } else { model.loadPrayer(prayer) }
            autoLockManager.disableAutoLock()
        }
        .onDisappear() {
            // Keep the covered reader and its scroll position while the shared page is open.
            if !shared && model.presentedSheet != .sharedPrayer { model.unloadPrayer() }
            autoLockManager.enableAutoLock()
        }
        .onChange(of: needsReload) { needsReload in
            if needsReload {
                print("PrayerScreen: Reloading prayer due to WebView state loss")
                if shared { model.loadSharedPrayer() } else { model.loadPrayer(prayer) }
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
        .onReceive(NotificationCenter.default.publisher(for: SharedPrayerSession.willOpen)) { _ in
            playbackSheetShown = false
            textOptionsShown = false
            sharingLink = nil
            model.externalLink = nil
            model.sharedExternalLink = nil
        }
        .onReceive(model.$pendingNavigation) { pending in
            if !shared, let pending = pending, case .prayer(let targetPrayer) = pending {
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
        var prevAppearanceCSS = ""
        var topPadding: CGFloat = 0
        var bottomPadding: CGFloat = 0
        var isWebViewReady = false
        
        init(parent: PrayerView) {
            self.parent = parent
            super.init()
            
            // This view is not updated if TextOptions is changed in the popover, so we rely on NotificationCenter instead
            NotificationCenter.default.addObserver(self, selector: #selector(onTextOptionsChanged(_:)), name: TextOptions.notificationName, object: nil)
            NotificationCenter.default.addObserver(self, selector: #selector(onScreenshotAction(_:)), name: ScreenshotMode.actionNotification, object: nil)
            
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
            if let textOptions = notification.object as? TextOptions, textOptions === parent.textOptions {
                setPrayerText(text: prevText, fontName: textOptions.fontName.systemName, fontSize: textOptions.fontSize,
                              isBold: textOptions.isBold, appearanceCSS: ReaderAppearance.css(textOptions.extraParameters))
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
        
        private func javaScriptString(_ value: String) -> String {
            let data = try! JSONSerialization.data(withJSONObject: value, options: [.fragmentsAllowed])
            return String(data: data, encoding: .utf8)!
        }

        func setPrayerText(text: String, fontName: String, fontSize: Double, isBold: Bool, appearanceCSS: String) {
            if text != prevText {
                let modifiedText = getModifiedText(text: text, fontName: fontName, fontSize: fontSize, isBold: isBold, appearanceCSS: appearanceCSS)
                if prevText == "" || !isWebViewReady {
                    let baseURL = URL(fileURLWithPath: Bundle.main.bundlePath)
                    self.webView.loadHTMLString(modifiedText, baseURL: baseURL)
                } else {
                    self.webView.evaluateJavaScript("document.documentElement.innerHTML = \(javaScriptString(modifiedText)); initPrayer(); setFont(\(javaScriptString(fontName)), \(fontSize), \(isBold));") { [weak self] (_, error) in
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
            }
            if fontName != prevFontName || fontSize != prevFontSize || isBold != prevIsBold || appearanceCSS != prevAppearanceCSS {
                updatePresentation(fontName: fontName, fontSize: fontSize, isBold: isBold, appearanceCSS: appearanceCSS)
            }
        }

        private func updatePresentation(fontName: String, fontSize: Double, isBold: Bool, appearanceCSS: String) {
            prevFontName = fontName
            prevFontSize = fontSize
            prevIsBold = isBold
            prevAppearanceCSS = appearanceCSS
            guard isWebViewReady else { return }
            webView.evaluateJavaScript("""
                setFont(\(javaScriptString(fontName)), \(fontSize), \(isBold));
                document.getElementById('reader-appearance').textContent = \(javaScriptString(appearanceCSS));
                """) { _, error in
                if let error = error { print("Error setting reader appearance: \(error)") }
            }
        }

        func getModifiedText(text: String, fontName: String, fontSize: Double, isBold: Bool, appearanceCSS: String) -> String {
            let settings = SharedPrayerLink.rendered(in: text)?.parameters ?? [:]
            let word = UInt64(settings["o2"] ?? "") ?? 0
            let rounded = word & 65536 != 0
            return """
                <head>
                    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
                    <meta name="viewport" content="width=device-width, user-scalable=yes, initial-scale=1.0" />
                    <link rel="stylesheet" type="text/css" href="html/breviar.css" />
                    <link rel="stylesheet" type="text/css" href="html/breviar-normal-font.css" />
                    <link rel="stylesheet" type="text/css" href="html/breviar-rounded-corners.css" \(rounded ? "" : "disabled") />
                    <style type="text/css">
                        @import url("html/breviar-invert-colors.css") screen and (prefers-color-scheme: dark);
                        body { padding: \(topPadding)px 0 \(bottomPadding)px; }
                    </style>
                    <style id="reader-appearance">\(appearanceCSS)</style>
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
                            setFont(\(javaScriptString(fontName)), \(fontSize), \(isBold));
                            window.webkit.messageHandlers.checkAlive.postMessage(true);
                        }
                    </script>
                </head>
                <body onload="initPrayer()">\(text)</body>
            """
        }
        
        @objc func onScreenshotAction(_ notification: Notification) {
            guard case .scroll(let fraction)? = notification.userInfo?["action"] as? ScreenshotMode.Action else { return }
            let script = "window.scrollTo(0, Math.round((document.documentElement.scrollHeight - window.innerHeight) * \(fraction)))"
            webView.evaluateJavaScript(script) { _, _ in
                ScreenshotMode.signalReadyAfterAnimation()
            }
        }

        // WKNavigationDelegate
        func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
            print("PrayerView: WebView did finish loading")
            isWebViewReady = true
            // An import or native edit may have arrived while the document was loading.
            let options = parent.textOptions
            updatePresentation(fontName: options.fontName.systemName, fontSize: options.fontSize,
                               isBold: options.isBold, appearanceCSS: ReaderAppearance.css(options.extraParameters))
            ScreenshotMode.signalReady("prayer")
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
        context.coordinator.parent = self
        context.coordinator.setPrayerText(text: text, fontName: textOptions.fontName.systemName, fontSize: textOptions.fontSize,
                                          isBold: textOptions.isBold, appearanceCSS: ReaderAppearance.css(textOptions.extraParameters))
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
