//
//  NavigationBarToggler.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 04. 05..
//

import SwiftUI

struct NavigationBarToggler<Content:View>: UIViewControllerRepresentable {
    @Binding var navigationBarHidden: Bool
    var content: () -> Content

    class Coordinator: NSObject {
        var prevHidden = false
        
        func setNavigationBar(hidden: Bool, controller: UIViewController) {
            if hidden != prevHidden {
                prevHidden = hidden
                controller.navigationController?.setNavigationBarHidden(hidden, animated: true)
            }
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator()
    }
    
    func makeUIViewController(context: Context) -> some UIViewController {
        return UIHostingController(rootView: content())
    }
    
    func updateUIViewController(_ c: UIViewControllerType, context: Context) {
        guard let controller = c as? UIHostingController<Content> else { return }
        controller.rootView = content()
        context.coordinator.setNavigationBar(hidden: navigationBarHidden, controller: controller)
    }
}
