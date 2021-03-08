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
        let dataSource = TestDataSource()
        let model = BreviarModel(dataSource: dataSource)
        
        WindowGroup {
            MainScreen().environmentObject(model.load())
        }
    }
}
