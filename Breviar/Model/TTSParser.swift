//
//  TTSParser.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2022. 05. 21..
//

import Foundation
import WebKit

struct TTSDocument {
    let sections: [TTSSection]
    
    func numChars() -> Int {
        return self.sections.reduce(0) { n, section in n + section.numChars() }
    }
}

struct TTSSection {
    let lines: [TTSLine]
    
    func numChars() -> Int {
        return self.lines.reduce(0) { n, line in n + line.text.count }
    }
}

struct TTSLine {
    let text: String
    let lineEnding: TTSLineEnding
}

enum TTSLineEnding {
    case normal
    case shortPause
    case longPause
}

class TTSParser : NSObject, WKNavigationDelegate {
    var handler: (TTSDocument?, Error?) -> Void
    var webView: WKWebView = WKWebView()
    
    override init() {
        self.handler = {_, _ in }
    }
    
    func parseHTML(_ htmlBody: String, handler: @escaping (TTSDocument?, Error?) -> Void) {
        self.handler = handler
        let html = """
            <!DOCTYPE html>
            <head>
                <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>
                <link rel='stylesheet' type='text/css' href='html/breviar.css'>
                <link rel='stylesheet' type='text/css' href='html/breviar-voice-output.css'>
            </head>\n"
                <body>\(htmlBody)</body>
            </html>
        """
        let baseURL = URL(fileURLWithPath: Bundle.main.bundlePath)
        self.webView.navigationDelegate = self
        self.webView.loadHTMLString(html, baseURL: baseURL)
    }

    func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
        let getSpeechTextJS = """
            (function() {
                let tts_sections = document.getElementsByClassName('tts_section');
                for (let section of tts_sections) {
                    section.parentNode.insertBefore(document.createTextNode("\\n####\\n"), section);
                }
                return document.body.innerText;
            })()
        """
        self.webView.evaluateJavaScript(getSpeechTextJS) { result, error in
            guard let res = result else { self.handler(nil, DataSourceError.parseError); return }
            guard let ttsText = res as? String else { self.handler(nil, DataSourceError.parseError); return }
            let doc = self.parseText(ttsText)
            
            DispatchQueue.main.async {
                self.handler(doc, nil)
            }
        }
    }
    
    private func parseText(_ text: String) -> TTSDocument {
        var sections: [TTSSection] = []
        
        for sectionText in text.components(separatedBy: "\n####\n") {
            var lines: [TTSLine] = []
            for l in sectionText.components(separatedBy: .newlines) {
                let line = l.trimmingCharacters(in: .whitespaces)
                if line.count == 0 || line == "\"" {
                    continue
                }
                lines.append(TTSLine(text: l, lineEnding: .normal))
            }
            sections.append(TTSSection(lines: lines))
        }
        
        return TTSDocument(sections: sections)
    }
}
