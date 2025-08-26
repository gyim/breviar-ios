//
//  MigrationBanner.swift
//  Breviar
//
//  Migration notice banner for single-language apps
//

import SwiftUI

struct MigrationBanner: View {
    @Binding var isDismissed: Bool
    
    var body: some View {
        if AppConfig.SHOW_MIGRATION_NOTICE && !isDismissed {
            VStack(spacing: 0) {
                HStack(spacing: 12) {
                    // Warning icon
                    Image(systemName: "exclamationmark.triangle.fill")
                        .foregroundColor(.orange)
                        .font(.system(size: 20))
                    
                    VStack(alignment: .leading, spacing: 4) {
                        Text(AppConfig.migrationTitle)
                            .font(.headline)
                            .foregroundColor(.primary)
                        
                        Text(AppConfig.migrationMessage)
                            .font(.subheadline)
                            .foregroundColor(.secondary)
                            .fixedSize(horizontal: false, vertical: true)
                    }
                    
                    Spacer()
                    
                    // Dismiss button
                    Button(action: {
                        withAnimation(.easeInOut(duration: 0.3)) {
                            isDismissed = true
                        }
                    }) {
                        Image(systemName: "xmark")
                            .foregroundColor(.secondary)
                            .font(.system(size: 14))
                    }
                }
                .padding(.horizontal, 16)
                .padding(.vertical, 12)
                
                // App Store link button
                Button(action: {
                    if let url = URL(string: AppConfig.MIGRATION_APP_STORE_URL) {
                        UIApplication.shared.open(url)
                    }
                }) {
                    HStack {
                        Image(systemName: "arrow.up.forward.app")
                            .font(.system(size: 16))
                        Text(AppConfig.migrationDownloadButton)
                            .font(.subheadline)
                            .fontWeight(.medium)
                    }
                    .foregroundColor(.white)
                    .frame(maxWidth: .infinity)
                    .padding(.vertical, 10)
                    .background(Color.blue)
                    .cornerRadius(8)
                }
                .padding(.horizontal, 16)
                .padding(.bottom, 12)
            }
            .background(Color.yellow.opacity(0.1))
            .overlay(
                Rectangle()
                    .frame(height: 1)
                    .foregroundColor(Color.yellow.opacity(0.3)),
                alignment: .bottom
            )
        }
    }
}

struct MigrationBanner_Previews: PreviewProvider {
    static var previews: some View {
        VStack {
            MigrationBanner(isDismissed: .constant(false))
            Spacer()
        }
    }
}