//
//  InlinePopoverPresenter.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 28..
//

import SwiftUI

// InlinePopoverPresenter provides a workaround for a SwiftUI limitation: as of writing,
// it cannot show inline popovers on small screens (iPhones).
// This UIViewControllerRepresentable creates an UIViewController that configures popovers properly.
struct InlinePopoverPresenter<Popover:View, Content:View>: UIViewControllerRepresentable {
    var popover: () -> Popover
    @Binding var isPresented: Bool
    var content: () -> Content

    class Coordinator: NSObject, UIPopoverPresentationControllerDelegate {
        var parent: InlinePopoverPresenter
        var popoverShown = false
        
        init(_ parent: InlinePopoverPresenter) {
            self.parent = parent
        }
        
        func showPopover(controller: UIViewController, show: Bool) {
            if show && !popoverShown {
                popoverShown = true
                
                // Calculate source rectangle (navbar button in top right corner)
                // (TODO: make this a parameter to the view)
                //
                // NOTE: it would be easier to set popover.popoverPresentationController?.barButtonItem,
                // but then the popover moves away when its data is changed. This is probably a SwiftUI bug.
                let window = UIApplication.shared.windows[0]
                let sourceView = controller.navigationController!.navigationBar
                let r = sourceView.bounds
                let w = r.height // button width = navbar height
                let sourceRect = CGRect(x: r.origin.x + r.width - w - window.safeAreaInsets.right, y: r.origin.y, width: w, height: r.height)
                
                // Create popover
                let popover = UIHostingController(rootView: self.parent.popover())
                popover.preferredContentSize = popover.sizeThatFits(in:CGSize(width:300, height:300))
                popover.modalPresentationStyle = .popover
                popover.popoverPresentationController?.sourceView = sourceView
                popover.popoverPresentationController?.sourceRect = sourceRect
                popover.popoverPresentationController?.delegate = self
                controller.present(popover, animated: true)
            }
        }
        
        // UIViewControllerRepresentable methods

        @objc func adaptivePresentationStyle(for controller: UIPresentationController, traitCollection: UITraitCollection) -> UIModalPresentationStyle {
            return .none // Force popover style on iPhone
        }
        
        @objc func popoverPresentationControllerDidDismissPopover(_ popoverPresentationController: UIPopoverPresentationController) {
            self.popoverShown = false
            self.parent.isPresented = false
        }
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(self)
    }
    
    func makeUIViewController(context: Context) -> some UIViewController {
        return UIHostingController(rootView: content())
    }
    
    func updateUIViewController(_ controller: UIViewControllerType, context: Context) {
        context.coordinator.showPopover(controller: controller, show: isPresented)
    }
}
