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
    
    func getRequestString(_ request: [String: String]) -> String {
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

class RemoteCGIClient : CGIClient {
    var sessionConfig: URLSessionConfiguration
    var session: URLSession

    override init() {
        self.sessionConfig = URLSessionConfiguration.ephemeral
        self.sessionConfig.timeoutIntervalForResource = 5.0
        self.sessionConfig.waitsForConnectivity = false
        self.sessionConfig.allowsCellularAccess = true
        self.session = URLSession(configuration: self.sessionConfig)
    }
    
    var allowsCellularAccess: Bool {
        get {
            return self.sessionConfig.allowsCellularAccess
        }
        set(newValue) {
            if self.sessionConfig.allowsCellularAccess != newValue {
                self.sessionConfig.allowsCellularAccess = newValue
                self.session = URLSession(configuration: self.sessionConfig)
            }
        }
    }
    
    override func makeRequest(_ request: [String : String], handler: @escaping (Data?, Error?) -> Void) {
        // Generate URL
        let urlString = "https://lh.kbs.sk/cgi-bin/l.cgi?" + getRequestString(request)
        
        guard let urlcomps = URLComponents(string: urlString) else {
            print("Cannot parse URL: \(urlString)")
            handler(nil, CGIError.internalError)
            return
        }

        // Make HTTP query
        print("Making remote CGI query: \(urlString)")
        
        let task = self.session.dataTask(with: urlcomps.url!) { (data, response, error) in
            if error != nil {
                handler(nil, CGIError.networkError)
                return
            }
            
            if let resp = response as? HTTPURLResponse {
                if !(200...299).contains(resp.statusCode) {
                    handler(nil, CGIError.serverError)
                    return
                }
            }
            
            if let data = data {
                handler(data, nil)
            } else {
                handler(nil, CGIError.emptyResponse)
            }
        }
        task.resume()
    }
}

class LocalCGIClient : CGIClient {
    var queue = DispatchQueue(label: "breviar-cgi")
    
    override func makeRequest(_ request: [String : String], handler: @escaping (Data?, Error?) -> Void) {
        let requestString = getRequestString(request)
        print("Making local query: \(requestString)")
        
        self.queue.async {
            let result = BRCGIQuery.query(withArgs: requestString)
            handler(result, nil)
        }
    }
}
