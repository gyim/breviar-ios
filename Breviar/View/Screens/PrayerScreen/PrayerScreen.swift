//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

struct PrayerScreen: View {
    @State var textOptionsShown = false
    @StateObject var textOptions = TextOptions()
    var prayer: Prayer
    
    var body: some View {
        InlinePopoverPresenter( popover: { TextOptionsView(textOptions: textOptions) }, isPresented: $textOptionsShown) {
            LoadingView(value: .loaded("Hello World"), loadedBody: { s in
                Text(s)
            })
        }
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
