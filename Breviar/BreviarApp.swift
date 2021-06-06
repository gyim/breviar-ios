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
    @ObservedObject var model = BreviarModel.cgiModel()
    
    var body: some Scene {
        WindowGroup {
            MainScreen().environmentObject(model)
                .onAppear() {
                    // Set UI language
                    if let options = model.dataSourceOptions {
                        currentLanguage = options.language
                    }
                    
                    // Load an empty WKWebView so that it is faster to load on prayer screen
                    _ = WKWebView()
                }
                .fullScreenCover(isPresented: $model.dataSourceOptionsNeeded, content: {
                    DataSourceOptionsWizard().environmentObject(model)
                })
        }
    }
}
