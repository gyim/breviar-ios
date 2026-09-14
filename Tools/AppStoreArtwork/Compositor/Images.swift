import AppKit
import ImageIO
import SwiftUI
import UniformTypeIdentifiers

struct CompositorError: Error, CustomStringConvertible {
    let description: String
    init(_ description: String) { self.description = description }
}

enum Images {
    static func load(_ path: String) -> CGImage? {
        guard let source = CGImageSourceCreateWithURL(URL(fileURLWithPath: path) as CFURL, nil) else { return nil }
        return CGImageSourceCreateImageAtIndex(source, 0, nil)
    }

    static func crop(_ image: CGImage, to rect: [Double]) -> CGImage {
        let r = CGRect(x: rect[0], y: rect[1], width: rect[2], height: rect[3])
        return image.cropping(to: r) ?? image
    }

    /// Finds the celebration card on a main screen capture: the first white area at the
    /// centre column below the navigation bar. The rectangle is inset by two pixels so
    /// that the anti-aliased card edge is left out.
    static func detectCelebrationCard(in image: CGImage) -> [Double]? {
        let width = image.width, height = image.height
        guard let context = CGContext(data: nil, width: width, height: height, bitsPerComponent: 8, bytesPerRow: width * 4,
                                      space: CGColorSpace(name: CGColorSpace.sRGB)!,
                                      bitmapInfo: CGImageAlphaInfo.noneSkipLast.rawValue),
              let data = context.data else { return nil }
        context.draw(image, in: CGRect(x: 0, y: 0, width: width, height: height))
        let pixels = data.assumingMemoryBound(to: UInt8.self)
        func white(_ x: Int, _ y: Int) -> Bool {
            let i = (y * width + x) * 4
            return pixels[i] >= 250 && pixels[i + 1] >= 250 && pixels[i + 2] >= 250
        }
        let cx = width / 2
        var top = Int(Double(height) * 0.10)
        while top < height && !white(cx, top) { top += 1 }
        guard top < height - 20 else { return nil }
        let probe = top + 8
        var left = cx, right = cx
        while left > 0 && white(left - 1, probe) { left -= 1 }
        while right < width - 1 && white(right + 1, probe) { right += 1 }
        let column = right - 10
        var bottom = probe
        while bottom < height - 1 && white(column, bottom + 1) { bottom += 1 }
        let inset = 2.0
        return [Double(left) + inset, Double(top) + inset,
                Double(right - left + 1) - 2 * inset, Double(bottom - top + 1) - 2 * inset]
    }

    /// Redraws the image into an opaque sRGB bitmap so that the PNG has no alpha channel.
    static func flattened(_ image: CGImage) -> CGImage {
        let space = CGColorSpace(name: CGColorSpace.sRGB)!
        let context = CGContext(data: nil, width: image.width, height: image.height, bitsPerComponent: 8,
                                bytesPerRow: 0, space: space, bitmapInfo: CGImageAlphaInfo.noneSkipLast.rawValue)!
        let rect = CGRect(x: 0, y: 0, width: image.width, height: image.height)
        context.setFillColor(CGColor.white)
        context.fill(rect)
        context.draw(image, in: rect)
        return context.makeImage()!
    }

    static func writePNG(_ image: CGImage, to path: String) throws {
        let url = URL(fileURLWithPath: path)
        try FileManager.default.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
        guard let destination = CGImageDestinationCreateWithURL(url as CFURL, UTType.png.identifier as CFString, 1, nil) else {
            throw CompositorError("cannot create \(path)")
        }
        CGImageDestinationAddImage(destination, image, [kCGImagePropertyHasAlpha: false] as CFDictionary)
        guard CGImageDestinationFinalize(destination) else { throw CompositorError("cannot write \(path)") }
    }

    /// Renders a SwiftUI view at exactly `size` pixels (1 pt = 1 px).
    @MainActor
    static func render<V: View>(_ view: V, size: CGSize) -> CGImage? {
        let renderer = ImageRenderer(content: view.frame(width: size.width, height: size.height).clipped())
        renderer.scale = 1
        renderer.isOpaque = true
        renderer.proposedSize = ProposedViewSize(size)
        return renderer.cgImage.map(flattened)
    }

    /// Renders a SwiftUI view at its own ideal size.
    @MainActor
    static func renderFitting<V: View>(_ view: V) -> CGImage? {
        let renderer = ImageRenderer(content: view)
        renderer.scale = 1
        renderer.isOpaque = true
        return renderer.cgImage.map(flattened)
    }
}

extension CGImage {
    var aspect: CGFloat { CGFloat(width) / CGFloat(height) }
}
