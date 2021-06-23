//
//  CGIQuery.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 12..
//

import Foundation

enum CGIError : String, Error {
    case networkError = "Network error"
    case serverError = "Remote server returned an invalid response"
    case emptyResponse = "Empty response from server"
    case internalError = "Internal error"
}

class CGIClient {
    func makeRequest(_ request: [String: String], handler: @escaping (Data?, Error?) -> Void) {
        handler(nil, CGIError.serverError)
    }
    
    func getRequestString(_ request: [String: String]) -> String {
        var req = ""
        
        for item in request {
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
        
        let task = URLSession.shared.dataTask(with: urlcomps.url!) { (data, response, error) in
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
