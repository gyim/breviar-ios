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

    var body: some View {
        InlinePopoverPresenter( popover: { TextOptionsView(textOptions: textOptions) }, isPresented: $textOptionsShown) {
            LoadingView(value: prayerText, loadedBody: { text in
                PrayerView(text: text)
            })
        }
        .navigationTitle(prayer.name)
        .navigationBarTitleDisplayMode(.inline)
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
    
    class Coordinator {
        var parent: PrayerView
        
        var webView: WKWebView
        var prevText: String
        
        init(_ parent: PrayerView) {
            self.parent = parent
            self.webView = WKWebView()
            self.prevText = ""
        }
        
        func setPrayerText(text: String) {
            if text != prevText {
                prevText = text
                let baseURL = URL(string: "https://lh.kbs.sk/cgi-bin")
                self.webView.loadHTMLString(text, baseURL: baseURL)
            }
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(self)
    }
    
    func makeUIView(context: Context) -> WKWebView {
        return context.coordinator.webView
    }
    
    func updateUIView(_ uiView: WKWebView, context: Context) {
        context.coordinator.setPrayerText(text: text)
    }
}
