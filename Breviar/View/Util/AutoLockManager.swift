//
//  AutoLockManager.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2025. 09. 19.
//

import Foundation
import UIKit

class AutoLockManager: ObservableObject {
    // A temporary shared reader can cover another reader. Closing either one
    // must not release the other's request to keep the screen awake.
    private static var activeReaders = 0
    private var timer: Timer?
    private let timeoutInterval: TimeInterval = 30 * 60 // 30 minutes

    @Published private(set) var isAutoLockDisabled = false

    func disableAutoLock() {
        guard !isAutoLockDisabled else { return }

        Self.activeReaders += 1
        UIApplication.shared.isIdleTimerDisabled = true
        isAutoLockDisabled = true

        startTimer()
    }

    func enableAutoLock() {
        guard isAutoLockDisabled else { return }

        Self.activeReaders -= 1
        UIApplication.shared.isIdleTimerDisabled = Self.activeReaders > 0
        isAutoLockDisabled = false

        stopTimer()
    }

    private func startTimer() {
        stopTimer()

        timer = Timer.scheduledTimer(withTimeInterval: timeoutInterval, repeats: false) { [weak self] _ in
            self?.enableAutoLock()
        }
    }

    private func stopTimer() {
        timer?.invalidate()
        timer = nil
    }

    deinit {
        enableAutoLock()
    }
}
