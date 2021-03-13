//
//  PrayerScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 11..
//

import SwiftUI
import WebKit

struct PrayerScreen: View {
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

struct PrayerScreen_Previews: PreviewProvider {
    static var previews: some View {
        NavigationView {
            PrayerScreen(content: .loaded("<b>Hello world</b>"))
                .navigationTitle(Text("Morning Prayer"))
        }
    }
}
