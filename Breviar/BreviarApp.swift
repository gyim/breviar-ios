//
//  BreviarApp.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 01. 16..
//

import SwiftUI

@main
struct BreviarApp: App {
    var body: some Scene {
        WindowGroup {
            MainScreen().environmentObject(BreviarModel.cgiModel())
        }
    }
}
