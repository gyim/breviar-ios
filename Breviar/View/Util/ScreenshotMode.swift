//
//  ScreenshotMode.swift
//  Breviar
//
//  Drives the app into the states needed for the App Store screenshots,
//  see Tools/AppStoreArtwork/README.md.
//
//  Screenshot mode is enabled with the `-screenshotMode 1` launch argument
//  (debug builds only). Two more launch arguments describe what to show:
//
//    -screenshotURL breviar://2026-09-20/morningprayer   navigation, same syntax as the URL scheme
//    -screenshotActions fullscreen,scroll:0.28           UI states to reach afterwards, in order
//
//  The screens observe the actions as notifications and flip their state.
//  Progress is reported as `SCREENSHOT_READY <tag>` lines in
//  Documents/screenshot-ready.log inside the app container (and on stderr);
//  the capture script waits for the `done` tag before taking the screenshot.
//

import SwiftUI

enum ScreenshotMode {
    #if DEBUG
    static let isActive = UserDefaults.standard.bool(forKey: "screenshotMode")
    #else
    static let isActive = false
    #endif

    static let actionNotification = Notification.Name("BreviarScreenshotAction")

    /// Navigates like an incoming breviar:// URL; installed by BreviarApp.
    static var openURL: ((URL) -> Void)?

    enum Action: Equatable {
        /// Scrolls the prayer text to a fraction (0...1) of its height.
        case scroll(Double)
        case textOptions
        case playback
        case fullscreen
        case datePicker
        case settings
        /// Opens the n-th visible flag set entry of the settings screen.
        case settingsFlagSet(Int)
    }

    /// Parses one action, e.g. "textOptions", "scroll:0.28" or "settingsFlagSet:1".
    static func action(from string: String) -> Action? {
        let parts = string.split(separator: ":", maxSplits: 1).map(String.init)
        let argument = parts.count > 1 ? parts[1] : nil
        switch parts.first {
        case "scroll": return argument.flatMap(Double.init).map(Action.scroll)
        case "textOptions": return .textOptions
        case "playback": return .playback
        case "fullscreen": return .fullscreen
        case "datePicker": return .datePicker
        case "settings": return .settings
        case "settingsFlagSet": return .settingsFlagSet(argument.flatMap(Int.init) ?? 0)
        default: return nil
        }
    }

    static func dispatch(_ action: Action) {
        guard isActive else { return }
        NotificationCenter.default.post(name: actionNotification, object: nil, userInfo: ["action": action])
    }

    private static let readyFile = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0]
        .appendingPathComponent("screenshot-ready.log")

    /// Records that a state has been reached: "day", "prayer", "action" or "done".
    static func signalReady(_ tag: String) {
        guard isActive else { return }
        let data = "SCREENSHOT_READY \(tag)\n".data(using: .utf8)!
        FileHandle.standardError.write(data)
        if let handle = try? FileHandle(forWritingTo: readyFile) {
            handle.seekToEndOfFile()
            handle.write(data)
            handle.closeFile()
        } else {
            try? data.write(to: readyFile)
        }
        Runner.shared.didReach(tag)
    }

    /// Reports `action` once the presentation animation started by an action has settled.
    static func signalReadyAfterAnimation(delay: Double = 0.8) {
        guard isActive else { return }
        DispatchQueue.main.asyncAfter(deadline: .now() + delay) {
            signalReady("action")
        }
    }

    /// Executes the launch arguments: navigates to `-screenshotURL` once the first day has
    /// loaded, then runs the `-screenshotActions` one after the other and reports `done`.
    /// A step that never reports back is skipped after a timeout, so a capture can never hang.
    final class Runner {
        static let shared = Runner()

        private enum State {
            case launching
            case navigating(expecting: String)
            case acting(Int)
            case finished
        }

        private var state = State.launching
        private var timeout: DispatchWorkItem?
        private let url = UserDefaults.standard.string(forKey: "screenshotURL").flatMap { URL(string: $0) }
        private let actions = (UserDefaults.standard.string(forKey: "screenshotActions") ?? "")
            .split(separator: ",")
            .compactMap { ScreenshotMode.action(from: String($0)) }

        func didReach(_ tag: String) {
            switch state {
            case .launching where tag == "day":
                navigate()
            case .navigating(let expected) where tag == expected:
                run(actionAt: 0)
            case .acting(let index) where tag == "action":
                run(actionAt: index + 1)
            default:
                break
            }
        }

        private func navigate() {
            guard let url, let openURL = ScreenshotMode.openURL else {
                run(actionAt: 0)
                return
            }
            let opensPrayer = url.pathComponents.filter { $0 != "/" }.count == 1
            state = .navigating(expecting: opensPrayer ? "prayer" : "day")
            openURL(url)
            armTimeout(seconds: 10) { self.run(actionAt: 0) }
        }

        private func run(actionAt index: Int) {
            timeout?.cancel()
            guard index < actions.count else {
                state = .finished
                ScreenshotMode.signalReady("done")
                return
            }
            state = .acting(index)
            ScreenshotMode.dispatch(actions[index])
            armTimeout(seconds: 6) { self.run(actionAt: index + 1) }
        }

        private func armTimeout(seconds: Double, _ handler: @escaping () -> Void) {
            let item = DispatchWorkItem(block: handler)
            timeout = item
            DispatchQueue.main.asyncAfter(deadline: .now() + seconds, execute: item)
        }
    }
}

extension View {
    /// Runs `handler` for every screenshot action while screenshot mode is active.
    func onScreenshotAction(_ handler: @escaping (ScreenshotMode.Action) -> Void) -> some View {
        onReceive(NotificationCenter.default.publisher(for: ScreenshotMode.actionNotification)) { notification in
            if let action = notification.userInfo?["action"] as? ScreenshotMode.Action {
                handler(action)
            }
        }
    }
}
