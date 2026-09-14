//
//  CGIQuery.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 12..
//

import Foundation

enum CGIError : LocalizedError {
    case networkError
    case serverError
    case emptyResponse
    case internalError
    
    public var errorDescription: String? {
        switch self {
        case .networkError:
            return S.errNetworkError.S
        case .serverError:
            return S.errServerError.S
        case .emptyResponse:
            return S.errEmptyResponse.S
        case .internalError:
            return S.errInternalError.S
        }
    }
}

class CGIClient {
    func makeRequest(_ request: [String: String], handler: @escaping (Data?, Error?) -> Void) {
        handler(nil, CGIError.serverError)
    }
    
    static func getRequestString(_ request: [String: String]) -> String {
        var req = ""
        var allParameters = request
        
        allParameters["appPlatform"] = "ios"
        
        if let bundleVersion = Bundle.main.object(forInfoDictionaryKey: "CFBundleVersion") as? String {
            allParameters["appVersion"] = bundleVersion
        }
        
        for item in allParameters {
            if req == "" {
                req += "\(item.key)=\(item.value)"
            } else {
                req += "&\(item.key)=\(item.value)"
            }
        }
        
        return req
    }
}

/// Failure of a single remote attempt.
enum RemoteFailure: Error {
    /// The device itself has no usable connection.
    case offline
    case timedOut
    case cancelled
    case transient(URLError.Code)
    case httpStatus(Int)
    /// A cross-host redirect was refused (typically a captive portal).
    case redirected
    case emptyResponse
    /// The response could not be parsed, so it did not come from the breviary server.
    case invalidContent

    var isRetryable: Bool {
        switch self {
        case .transient, .emptyResponse, .invalidContent:
            return true
        case .httpStatus(let code):
            return code >= 500
        case .offline, .timedOut, .cancelled, .redirected:
            return false
        }
    }
    
    /// Whether this failure means that the server (and not the connectivity) is at fault.
    var startsCooldown: Bool {
        switch self {
        case .offline, .cancelled:
            return false
        default:
            return true
        }
    }
}
        
/// Single attempt HTTP client for the remote CGI. Retries are scheduled by `CGIDataSource`.
final class RemoteCGIClient: NSObject, URLSessionTaskDelegate {
    private lazy var session: URLSession = {
        let config = URLSessionConfiguration.ephemeral
        config.waitsForConnectivity = false
        // The per-request flags decide; the session only provides a safety net.
        config.allowsCellularAccess = true
        config.timeoutIntervalForRequest = NetworkConstants.onlineAttemptBudget + 1
        config.timeoutIntervalForResource = NetworkConstants.onlineAttemptBudget + 1
        return URLSession(configuration: config, delegate: self, delegateQueue: nil)
    }()

    /// Makes one request. The completion runs on the session's queue so that the caller
    /// can parse the response there before hopping to the main queue.
    func fetch(_ request: [String: String], allowsCellularAccess: Bool, timeout: TimeInterval, completion: @escaping (Result<Data, RemoteFailure>) -> Void) {
        let urlString = "https://\(NetworkConstants.serverHost)/cgi-bin/l.cgi?" + CGIClient.getRequestString(request)

        guard let url = URLComponents(string: urlString)?.url else {
            print("Cannot parse URL: \(urlString)")
            completion(.failure(.invalidContent))
            return
        }

        print("Making remote CGI query: \(urlString)")
        
        var urlRequest = URLRequest(url: url, timeoutInterval: timeout)
        urlRequest.allowsCellularAccess = allowsCellularAccess
            
        let task = self.session.dataTask(with: urlRequest) { data, response, error in
            completion(RemoteCGIClient.validate(data: data, response: response, error: error))
        }
        task.resume()
    }

    private static func validate(data: Data?, response: URLResponse?, error: Error?) -> Result<Data, RemoteFailure> {
        if let error = error {
            return .failure(failure(for: error))
        }

        if let httpResponse = response as? HTTPURLResponse {
            if (300...399).contains(httpResponse.statusCode) {
                return .failure(.redirected)
            }
            if !(200...299).contains(httpResponse.statusCode) {
                return .failure(.httpStatus(httpResponse.statusCode))
            }
        }

        // A different host means that something else answered for the server
        if response?.url?.host != NetworkConstants.serverHost {
            return .failure(.redirected)
        }

        guard let data = data, !data.isEmpty else {
            return .failure(.emptyResponse)
        }

        return .success(data)
    }

    private static func failure(for error: Error) -> RemoteFailure {
        guard let urlError = error as? URLError else {
            return .transient(.unknown)
        }

        switch urlError.code {
        case .notConnectedToInternet, .dataNotAllowed, .internationalRoamingOff, .callIsActive:
            return .offline
        case .timedOut:
            return .timedOut
        case .cancelled:
            return .cancelled
        case .httpTooManyRedirects:
            return .redirected
        default:
            return .transient(urlError.code)
        }
    }

    func urlSession(_ session: URLSession, task: URLSessionTask, willPerformHTTPRedirection response: HTTPURLResponse, newRequest request: URLRequest, completionHandler: @escaping (URLRequest?) -> Void) {
        // Redirects to another host are captive portals, not the breviary server
        if request.url?.host == task.originalRequest?.url?.host {
            completionHandler(request)
        } else {
            completionHandler(nil)
        }
    }
}

class LocalCGIClient : CGIClient {
    var queue = DispatchQueue(label: "breviar-cgi")
    
    override func makeRequest(_ request: [String : String], handler: @escaping (Data?, Error?) -> Void) {
        let requestString = CGIClient.getRequestString(request)
        print("Making local query: \(requestString)")
        
        self.queue.async {
            let result = BRCGIQuery.query(withArgs: requestString)
            handler(result, nil)
        }
    }
}
