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
                Text("Loading...").padding()
            case .failed(let error):
                Image(systemName: "exclamationmark.triangle")
                    .resizable()
                    .frame(width: 50, height: 50, alignment: .center)
                    .foregroundColor(.red)
                Text(error.localizedDescription)
                    .multilineTextAlignment(.center)
                    .padding()
            case .loaded(let body):
                loadedBody(body)
            }
        }
    }
}

struct LoadingView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            LoadingView(value: .loading) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 200.0))

            LoadingView(value: .failed(DataSourceError.emptyResponse)) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 200.0))
                .preferredColorScheme(.dark)

            LoadingView(value: .loaded("This is the content.")) {(s: String) in Text(s) }
                .previewLayout(.fixed(width: 300.0, height: 200.0))
        }
    }
}
