//
//  NetworkStatus.swift
//  Breviar
//
//  Network state of the data source and the constants driving the online
//  attempts, the fallback to the local CGI and the main screen indicator.
//

import Foundation

/// Where a single load is allowed to take its data from.
enum DataSourcePolicy {
    /// Follow the data source settings, the connectivity and the server cooldown.
    case automatic
    /// Never touch the network (widget cache, "Try offline" button).
    case forceLocal
    /// Explicit user request: try the server even in Wi-Fi-only mode or during the cooldown.
    case forceRemote
}

enum OfflineReason: Equatable {
    case noConnection
    case wifiRequired
    case serverUnreachable
}

enum NetworkIndicatorState: Equatable {
    case hidden
    case loading
    case offline
}

enum NetworkConstants {
    static let serverHost = "lh.kbs.sk"
    /// Wall clock budget for one load: first attempt plus all retries.
    static let onlineAttemptBudget: TimeInterval = 2.0
    /// Delay before the first retry, doubled after each failed attempt.
    static let initialRetryDelay: TimeInterval = 0.25
    /// No new attempt is started with less time than this left from the budget.
    static let minimumAttemptTime: TimeInterval = 0.3
    static let serverFailureCooldown: TimeInterval = 20 * 60
    /// The spinner only appears for loads that are slower than this.
    static let loadingIndicatorDelay: TimeInterval = 0.4
}

/// Observable network state of the data source.
///
/// Every mutator runs on the main queue: the data source takes all of its decisions there,
/// and SwiftUI observes the published values.
final class NetworkStatus: ObservableObject {
    @Published private(set) var activeRemoteRequests = 0
    /// Optimistic until the path monitor delivers its first update.
    @Published private(set) var isConnected = true
    @Published private(set) var isOnWifi = true
    @Published private(set) var dataSourceType: DataSourceType? = nil
    @Published private(set) var remoteCooldownUntil: Date? = nil
    /// True when the texts on screen come from the CGI built into the app.
    @Published private(set) var showsLocalContent = false

    var isCooldownActive: Bool {
        guard let until = self.remoteCooldownUntil else { return false }
        return Date() < until
    }

    var indicatorState: NetworkIndicatorState {
        if self.activeRemoteRequests > 0 {
            return .loading
        }
        if self.showsLocalContent && self.dataSourceType != .alwaysCGI {
            return .offline
        }
        return .hidden
    }

    var offlineReason: OfflineReason? {
        if !self.isConnected {
            return .noConnection
        }
        if self.dataSourceType == .networkOnWifi && !self.isOnWifi {
            return .wifiRequired
        }
        if self.isCooldownActive {
            return .serverUnreachable
        }
        return nil
    }

    func beginRemoteRequest() {
        dispatchPrecondition(condition: .onQueue(.main))
        self.activeRemoteRequests += 1
    }

    func endRemoteRequest() {
        dispatchPrecondition(condition: .onQueue(.main))
        if self.activeRemoteRequests > 0 {
            self.activeRemoteRequests -= 1
        }
    }

    func updatePath(isConnected: Bool, isOnWifi: Bool) {
        dispatchPrecondition(condition: .onQueue(.main))
        if self.isConnected != isConnected {
            self.isConnected = isConnected
        }
        if self.isOnWifi != isOnWifi {
            self.isOnWifi = isOnWifi
        }
    }

    func setDataSourceType(_ type: DataSourceType?) {
        dispatchPrecondition(condition: .onQueue(.main))
        if self.dataSourceType != type {
            self.dataSourceType = type
        }
        if type == .alwaysCGI {
            self.showsLocalContent = false
        }
    }

    func startCooldown() {
        dispatchPrecondition(condition: .onQueue(.main))
        let until = Date().addingTimeInterval(NetworkConstants.serverFailureCooldown)
        self.remoteCooldownUntil = until
        print("Server cooldown until \(until)")
    }

    func clearCooldown() {
        dispatchPrecondition(condition: .onQueue(.main))
        if self.remoteCooldownUntil != nil {
            self.remoteCooldownUntil = nil
        }
    }

    /// Records where the content of the finished load came from.
    func didFinishLoad(local: Bool) {
        dispatchPrecondition(condition: .onQueue(.main))
        // In the "Never" setting the user deliberately reads the built-in texts,
        // so the indicator never appears.
        guard self.dataSourceType != .alwaysCGI else { return }
        if self.showsLocalContent != local {
            self.showsLocalContent = local
        }
    }
}
