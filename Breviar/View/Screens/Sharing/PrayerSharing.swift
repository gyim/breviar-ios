import SwiftUI
import UIKit
import CoreImage.CIFilterBuiltins

struct SharingAlert: ViewModifier {
    @ObservedObject var model: BreviarModel
    let presenter: AppSheet?
    func body(content: Content) -> some View {
        content.alert(S.sharePrayer.S, isPresented: Binding(
            get: { model.sharingError != nil && model.presentedSheet == presenter },
            set: { if !$0 { model.sharingError = nil } }
        )) {
            Button(S.close.S, role: .cancel) { model.sharingError = nil }
        } message: { Text(model.sharingError ?? "") }
    }
}

struct PrayerShareSheet: View {
    let url: URL
    @Environment(\.dismiss) private var dismiss
    @State private var copied = false
    @State private var image: UIImage?

    var body: some View {
        NavigationView {
            ScrollView {
                VStack(spacing: 20) {
                    Text(S.sharePrayerMessage.S)
                    if let image = image {
                        Image(uiImage: image).interpolation(.none).resizable().scaledToFit()
                            .frame(maxWidth: 520).accessibilityLabel(S.sharePrayer.S)
                    } else { Text(S.sharePrayerUnavailable.S) }
                    Text(url.absoluteString).font(.caption).textSelection(.enabled)
                    NativePrayerShareButton(url: url).frame(height: 44)
                    Button(copied ? S.linkCopied.S : S.copyPrayerLink.S) {
                        UIPasteboard.general.url = url
                        copied = true
                    }
                }.padding()
            }
            .navigationTitle(S.sharePrayer.S).navigationBarTitleDisplayMode(.inline)
            .toolbar { ToolbarItem(placement: .cancellationAction) { Button(S.close.S) { dismiss() } } }
        }
        .navigationViewStyle(StackNavigationViewStyle())
        .preferredColorScheme(.light)
        .onAppear { image = Self.qrCode(url) }
    }

    static func qrCode(_ url: URL) -> UIImage? {
        let filter = CIFilter.qrCodeGenerator()
        filter.message = Data(url.absoluteString.utf8)
        filter.correctionLevel = "M"
        guard let output = filter.outputImage else { return nil }
        let scale = max(1, floor(768 / (output.extent.width + 8)))
        let scaled = output.transformed(by: CGAffineTransform(scaleX: scale, y: scale))
        guard let code = CIContext().createCGImage(scaled, from: scaled.extent) else { return nil }
        let margin = 4 * scale
        let size = CGSize(width: CGFloat(code.width) + 2 * margin, height: CGFloat(code.height) + 2 * margin)
        let format = UIGraphicsImageRendererFormat()
        format.scale = 1
        format.opaque = true
        return UIGraphicsImageRenderer(size: size, format: format).image { context in
            context.cgContext.setFillColor(UIColor.white.cgColor)
            context.cgContext.fill(CGRect(origin: .zero, size: size))
            context.cgContext.interpolationQuality = .none
            UIImage(cgImage: code).draw(at: CGPoint(x: margin, y: margin))
        }
    }
}

/// The actual tapped button anchors the iPad popover in the correct window/scene.
private struct NativePrayerShareButton: UIViewRepresentable {
    let url: URL
    func makeCoordinator() -> Coordinator { Coordinator(url: url) }
    func makeUIView(context: Context) -> UIButton {
        let button = UIButton(type: .system)
        button.setTitle(S.sharePrayerLink.S, for: .normal)
        button.addTarget(context.coordinator, action: #selector(Coordinator.share(_:)), for: .touchUpInside)
        return button
    }
    func updateUIView(_ view: UIButton, context: Context) { context.coordinator.url = url }

    final class Coordinator: NSObject {
        var url: URL
        init(url: URL) { self.url = url; super.init() }
        @objc func share(_ button: UIButton) {
            var responder: UIResponder? = button
            while let current = responder {
                if let controller = current as? UIViewController {
                    let activity = UIActivityViewController(activityItems: [url], applicationActivities: nil)
                    activity.popoverPresentationController?.sourceView = button
                    activity.popoverPresentationController?.sourceRect = button.bounds
                    controller.present(activity, animated: true)
                    return
                }
                responder = current.next
            }
        }
    }
}

struct SharedPrayerScreen: View {
    @EnvironmentObject var model: BreviarModel
    var body: some View {
        NavigationView {
            PrayerScreen(prayer: model.sharedPrayer, prayerText: $model.sharedPrayerText,
                         textOptions: $model.textOptions, shared: true)
                .toolbar {
                    ToolbarItem(placement: .navigationBarLeading) {
                        Menu {
                            if model.sharedSessionActive {
                                Text(S.sharedSettingsTemporary.S)
                                Button(S.restorePrayerSettings.S) { model.restorePersonalSettings() }
                                Button(S.keepPrayerSettings.S) { model.keepSharedSettings() }
                                    .disabled(model.sharedResolvedLink == nil)
                            }
                            Button(S.back.S) { model.presentedSheet = nil }
                        } label: { Label(S.sharedPrayer.S, systemImage: "ellipsis.circle") }
                    }
                }
        }.navigationViewStyle(StackNavigationViewStyle())
    }
}

struct SharedPrayerControls: View {
    @EnvironmentObject var model: BreviarModel
    var body: some View {
        if model.sharedSessionActive {
            VStack(spacing: 6) {
                Text(S.sharedSettingsTemporary.S).font(.caption)
                HStack {
                    Button(S.sharedPrayer.S) { model.presentedSheet = .sharedPrayer }
                    Spacer()
                    Button(S.restorePrayerSettings.S) { model.restorePersonalSettings() }
                    Button(S.keepPrayerSettings.S) { model.keepSharedSettings() }
                        .disabled(model.sharedResolvedLink == nil)
                }.font(.caption)
            }.padding().background(Color(UIColor.systemBackground))
        }
    }
}
