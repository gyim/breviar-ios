//
//  LoadingView.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 27..
//

import SwiftUI

struct LoadingView<T, Content: View> : View {
    var value: LoadingState<T>
    var loadedBody: (T) -> Content
    
    var body: some View {
        VStack {
            switch(value) {
            case .idle, .loading:
                ProgressView().progressViewStyle(CircularProgressViewStyle())
                Text(S.loading.S).padding()
            case .failed(let error, let retry):
                VStack {
                    Image(systemName: "exclamationmark.triangle")
                        .resizable()
                        .frame(width: 80, height: 80, alignment: .center)
                        .foregroundColor(.red)
                    Text(error.localizedDescription)
                        .font(.headline)
                        .multilineTextAlignment(.center)
                        .padding()
                    HStack {
                        RetryButton(label: S.retryFromServer.S, action: retry, forceLocal: false)
                        RetryButton(label: S.retryLocally.S, action: retry, forceLocal: true)
                    }
                }.padding()
            case .loaded(let body):
                loadedBody(body)
            }
        }
    }
}

struct RetryButton: View {
    var label: String
    var action: (_ forceLocal: Bool) -> Void
    var forceLocal: Bool

    var body: some View {
        Button(action: {
            action(forceLocal)
        }, label: {
            Text(label)
                .multilineTextAlignment(.center)
                .foregroundColor(.white)
        })
        .padding()
        .frame(maxWidth: .infinity)
        .background(Color.blue)
        .cornerRadius(10.0)
    }
}

struct LoadingView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            LoadingView(value: .loading) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 200.0))

            LoadingView(value: .failed(DataSourceError.emptyResponse, {forceLocal in print("Retry: \(forceLocal)")})) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 400.0))
                .preferredColorScheme(.dark)

            LoadingView(value: .loaded("This is the content.")) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 200.0))
        }
    }
}
