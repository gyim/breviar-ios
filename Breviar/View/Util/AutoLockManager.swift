//
//  AutoLockManager.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2025. 09. 19.
//

import Foundation
import UIKit

class AutoLockManager: ObservableObject {
    private var timer: Timer?
    private let timeoutInterval: TimeInterval = 30 * 60 // 30 minutes

    @Published private(set) var isAutoLockDisabled = false

    func disableAutoLock() {
        guard !isAutoLockDisabled else { return }

        UIApplication.shared.isIdleTimerDisabled = true
        isAutoLockDisabled = true

        startTimer()
    }

    func enableAutoLock() {
        guard isAutoLockDisabled else { return }

        UIApplication.shared.isIdleTimerDisabled = false
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
