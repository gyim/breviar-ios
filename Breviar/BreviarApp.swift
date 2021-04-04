//
//  BreviarApp.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 16..
//

import SwiftUI
import WebKit

@main
struct BreviarApp: App {
    var body: some Scene {
        WindowGroup {
            MainScreen().environmentObject(BreviarModel.cgiModel())
                .onAppear() {
                    // Load an empty WKWebView so that it is faster to load on prayer screen
                    _ = WKWebView()
                }
        }
    }
}
