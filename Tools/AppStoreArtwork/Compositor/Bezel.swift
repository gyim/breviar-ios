import SwiftUI

/// A device bezel image with a transparent screen cutout (Apple's Product Bezels).
struct Bezel {
    let image: CGImage
    /// The transparent screen area, in bezel pixels, origin top left.
    let screenRect: CGRect

    var screenAspect: CGFloat { screenRect.width / screenRect.height }

    static func load(_ path: String) -> Bezel? {
        guard let image = Images.load(path), let rect = detectScreenRect(image) else { return nil }
        return Bezel(image: image, screenRect: rect)
    }

    /// Walks from the centre pixel outwards along the alpha channel until the bezel starts.
    static func detectScreenRect(_ image: CGImage) -> CGRect? {
        let width = image.width, height = image.height
        guard let context = CGContext(data: nil, width: width, height: height, bitsPerComponent: 8, bytesPerRow: width * 2,
                                      space: CGColorSpaceCreateDeviceGray(),
                                      bitmapInfo: CGImageAlphaInfo.premultipliedLast.rawValue),
              let data = context.data else { return nil }
        context.draw(image, in: CGRect(x: 0, y: 0, width: width, height: height))
        let pixels = data.assumingMemoryBound(to: UInt8.self)
        func transparent(_ x: Int, _ y: Int) -> Bool { pixels[(y * width + x) * 2 + 1] < 16 }
        let cx = width / 2, cy = height / 2
        guard transparent(cx, cy) else { return nil }
        var left = cx, right = cx, top = cy, bottom = cy
        while left > 0 && transparent(left - 1, cy) { left -= 1 }
        while right < width - 1 && transparent(right + 1, cy) { right += 1 }
        while top > 0 && transparent(cx, top - 1) { top -= 1 }
        while bottom < height - 1 && transparent(cx, bottom + 1) { bottom += 1 }
        return CGRect(x: left, y: top, width: right - left + 1, height: bottom - top + 1)
    }
}

enum DeviceGeometry {
    /// The screen area actually drawn for a requested screen width: with a bezel the
    /// height follows the bezel's cutout, otherwise the capture's aspect ratio.
    static func screenSize(width: CGFloat, aspect: CGFloat, bezel: Bezel?) -> CGSize {
        CGSize(width: width, height: width / (bezel?.screenAspect ?? aspect))
    }

    static func totalSize(spec: DeviceSpec, bezel: Bezel?, screenSize: CGSize) -> CGSize {
        if let bezel {
            let k = screenSize.width / bezel.screenRect.width
            return CGSize(width: CGFloat(bezel.image.width) * k, height: CGFloat(bezel.image.height) * k)
        }
        let t = spec.bezelThickness
        return CGSize(width: screenSize.width + 2 * t, height: screenSize.height + 2 * t)
    }

    /// The largest screen with the given aspect ratio whose device frame fits into `box`.
    static func fitScreen(aspect: CGFloat, in box: CGSize, spec: DeviceSpec, bezel: Bezel?) -> CGSize {
        if let bezel {
            let unit = totalSize(spec: spec, bezel: bezel, screenSize: screenSize(width: 1000, aspect: aspect, bezel: bezel))
            let k = min(box.width / unit.width, box.height / unit.height)
            return screenSize(width: 1000 * k, aspect: aspect, bezel: bezel)
        }
        let t = spec.bezelThickness
        let width = min(box.width - 2 * t, (box.height - 2 * t) * aspect)
        return CGSize(width: width, height: width / aspect)
    }
}

/// A device frame around screen content: Apple's bezel image if available, a drawn frame otherwise.
struct DeviceFrame<Content: View>: View {
    let spec: DeviceSpec
    let bezel: Bezel?
    let screenSize: CGSize
    @ViewBuilder let content: (CGSize) -> Content

    private var screenRadius: CGFloat { spec.screenCornerRadius * screenSize.width / spec.captureWidth }

    var body: some View {
        let total = DeviceGeometry.totalSize(spec: spec, bezel: bezel, screenSize: screenSize)
        ZStack(alignment: .topLeading) {
            if let bezel {
                let k = screenSize.width / bezel.screenRect.width
                screen
                    .offset(x: bezel.screenRect.minX * k, y: bezel.screenRect.minY * k)
                Image(decorative: bezel.image, scale: 1)
                    .resizable()
                    .interpolation(.high)
                    .frame(width: total.width, height: total.height)
            } else {
                let t = spec.bezelThickness
                RoundedRectangle(cornerRadius: screenRadius + t, style: .continuous)
                    .fill(Color(white: 0.07))
                    .frame(width: total.width, height: total.height)
                RoundedRectangle(cornerRadius: screenRadius + t, style: .continuous)
                    .strokeBorder(Color(white: 0.30), lineWidth: 2)
                    .frame(width: total.width, height: total.height)
                screen
                    .offset(x: t, y: t)
            }
        }
        .frame(width: total.width, height: total.height, alignment: .topLeading)
    }

    private var screen: some View {
        content(screenSize)
            .frame(width: screenSize.width, height: screenSize.height)
            .clipShape(RoundedRectangle(cornerRadius: screenRadius, style: .continuous))
    }
}
