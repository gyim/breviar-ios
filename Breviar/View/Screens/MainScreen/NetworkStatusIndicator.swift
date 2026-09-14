//
//  NetworkStatusIndicator.swift
//  Breviar
//
//  Navigation bar indicator of the main screen: a spinner while the server is
//  queried, and an offline icon while the texts come from the built-in CGI.
//

import SwiftUI

struct NetworkStatusIndicator: View {
    @ObservedObject var status: NetworkStatus
    var onRetryOnline: () -> Void

    @State private var spinnerVisible = false
    @State private var spinnerToken = 0
    @State private var popoverShown = false

    private var indicatorState: NetworkIndicatorState {
        if ScreenshotMode.isActive {
            return .hidden
        }
        if spinnerVisible {
            return .loading
        }
        return status.indicatorState == .offline ? .offline : .hidden
    }

    var body: some View {
        let state = indicatorState

        return Button(
            action: {
                popoverShown = true
            },
            label: {
                ZStack {
                    ProgressView()
                        .opacity(state == .loading ? 1 : 0)
                    Image(systemName: "wifi.slash")
                        .foregroundColor(.secondary)
                        .opacity(state == .offline ? 1 : 0)
                }
                .frame(width: 32)
            })
            // The indicator always stays in the view hierarchy and collapses its width to
            // zero, see the TodayButton doc comment in MainScreen.swift
            .frame(width: state == .hidden ? 0 : 32, alignment: .leading)
            .clipped()
            // Not .disabled(): that would dim the spinner as well
            .allowsHitTesting(state == .offline)
            .accessibilityHidden(state == .hidden)
            .accessibilityLabel(state == .offline ? S.offlineMode.S : S.loading.S)
            .animatingChanges(of: state)
            .onAppear {
                updateSpinner(loading: status.activeRemoteRequests > 0)
            }
            .onChange(of: status.activeRemoteRequests > 0) { loading in
                updateSpinner(loading: loading)
            }
            .popover(isPresented: $popoverShown) {
                OfflineInfoView(reason: status.offlineReason) {
                    popoverShown = false
                    onRetryOnline()
                }
            }
    }

    /// Shows the spinner only for loads that are slower than `loadingIndicatorDelay`,
    /// so that fast loads do not make the navigation bar flicker.
    private func updateSpinner(loading: Bool) {
        spinnerToken += 1
        let token = spinnerToken

        guard loading else {
            spinnerVisible = false
            return
        }

        DispatchQueue.main.asyncAfter(deadline: .now() + NetworkConstants.loadingIndicatorDelay) {
            if token == spinnerToken {
                spinnerVisible = true
            }
        }
    }
}

struct OfflineInfoView: View {
    var reason: OfflineReason?
    var onRetry: () -> Void

    private var reasonText: String? {
        switch reason {
        case .noConnection:
            return S.offlineNoConnection.S
        case .wifiRequired:
            return S.offlineWifiRequired.S
        case .serverUnreachable:
            return S.offlineServerUnreachable.S
        case nil:
            return nil
        }
    }

    var body: some View {
        let content = VStack(alignment: .leading, spacing: 12) {
            Label(S.offlineMode.S, systemImage: "wifi.slash")
                .font(.headline)
            Text(S.offlineExplanation.S)
                .font(.subheadline)
            if let reasonText = reasonText {
                Text(reasonText)
                    .font(.footnote)
                    .foregroundColor(.secondary)
            }
            Button(
                action: onRetry,
                label: {
                    Text(reason == .wifiRequired ? S.downloadOverCellular.S : S.loadFromInternet.S)
                        .foregroundColor(.white)
                        .padding()
                        .frame(maxWidth: .infinity)
                        .background(Color.accentColor)
                        .cornerRadius(10.0)
                })
        }
        .padding()
        .frame(width: 300)

        return content.presentedAsPopover()
    }
}

private extension View {
    /// `animation(_:value:)` needs iOS 15, the app still supports iOS 14.
    func animatingChanges<V: Equatable>(of value: V) -> AnyView {
        if #available(iOS 15.0, *) {
            return AnyView(self.animation(.easeInOut(duration: 0.2), value: value))
        }
        return AnyView(self)
    }

    /// Keeps the popover a popover on the iPhone instead of letting it become a sheet.
    func presentedAsPopover() -> AnyView {
        if #available(iOS 16.4, *) {
            return AnyView(self.presentationCompactAdaptation(.popover))
        }
        if #available(iOS 16.0, *) {
            return AnyView(self.presentationDetents([.medium]))
        }
        return AnyView(self)
    }
}

struct OfflineInfoView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            OfflineInfoView(reason: .noConnection) {}
            OfflineInfoView(reason: .wifiRequired) {}
            OfflineInfoView(reason: nil) {}
                .preferredColorScheme(.dark)
        }
        .previewLayout(.sizeThatFits)
    }
}
