import SwiftUI

extension Color {
    init(hex: String) {
        var s = hex.trimmingCharacters(in: .whitespaces)
        if s.hasPrefix("#") { s.removeFirst() }
        let v = UInt64(s, radix: 16) ?? 0
        self.init(red: Double((v >> 16) & 0xFF) / 255, green: Double((v >> 8) & 0xFF) / 255, blue: Double(v & 0xFF) / 255)
    }
}

/// Everything a layout needs besides its images.
struct ShotContext {
    let spec: DeviceSpec
    let style: Style
    let bezel: Bezel?
    let caption: Caption
    let layout: ShotLayout

    var background: LinearGradient {
        LinearGradient(colors: style.background.map { Color(hex: $0) }, startPoint: .top, endPoint: .bottom)
    }
}

extension View {
    func deviceShadow() -> some View {
        shadow(color: .black.opacity(0.16), radius: 40, x: 0, y: 24)
    }
}

/// The paper background with the standard margins.
struct Artboard<Content: View>: View {
    let ctx: ShotContext
    var bleedBottom = false
    @ViewBuilder let content: () -> Content

    var body: some View {
        ZStack(alignment: .topLeading) {
            ctx.background
            content()
                .padding(.horizontal, ctx.spec.margin)
                .padding(.top, ctx.spec.margin)
                .padding(.bottom, bleedBottom ? 0 : ctx.spec.bottomMargin)
        }
        .frame(width: ctx.spec.canvasSize.width, height: ctx.spec.canvasSize.height)
        .clipped()
        .environment(\.colorScheme, .light)
    }
}

/// A capture filling a screen of the given size.
struct ScreenImage: View {
    let image: CGImage
    let size: CGSize

    var body: some View {
        Image(decorative: image, scale: 1)
            .resizable()
            .interpolation(.high)
            .aspectRatio(contentMode: .fill)
            .frame(width: size.width, height: size.height)
            .clipped()
    }
}

struct CaptionBlock: View {
    let ctx: ShotContext

    var body: some View {
        VStack(alignment: .leading, spacing: ctx.spec.subtitleSize * 0.55) {
            Text(ctx.caption.title)
                .font(.system(size: ctx.spec.titleSize, weight: .semibold))
                .foregroundStyle(Color(hex: ctx.style.title))
                .lineLimit(2)
                .minimumScaleFactor(0.75)
                .fixedSize(horizontal: false, vertical: true)
            if let subtitle = ctx.caption.subtitle {
                Text(subtitle)
                    .font(.system(size: ctx.spec.subtitleSize))
                    .foregroundStyle(Color(hex: ctx.style.subtitle))
                    .lineLimit(2)
                    .minimumScaleFactor(0.75)
                    .fixedSize(horizontal: false, vertical: true)
            }
            if let badge = ctx.caption.badge {
                Badge(text: badge, symbol: ctx.layout.badgeSymbol, ctx: ctx)
            }
        }
        .frame(maxWidth: .infinity, alignment: .leading)
        .frame(height: ctx.spec.captionHeight, alignment: .topLeading)
    }
}

struct Badge: View {
    let text: String
    let symbol: String?
    let ctx: ShotContext

    var body: some View {
        HStack(spacing: 14) {
            if let symbol {
                Image(systemName: symbol)
            }
            Text(text)
        }
        .font(.system(size: ctx.spec.subtitleSize * 0.78, weight: .semibold))
        .foregroundStyle(Color.white)
        .padding(.horizontal, 30)
        .padding(.vertical, 14)
        .background(Capsule().fill(Color(hex: ctx.style.accent)))
    }
}

struct ChipView: View {
    let chip: Chip
    let ctx: ShotContext

    var body: some View {
        HStack(spacing: 14) {
            Text(chip.emoji)
                .font(.system(size: ctx.spec.subtitleSize * 0.8))
            Text(chip.text)
                .font(.system(size: ctx.spec.subtitleSize * 0.72, weight: .medium))
                .foregroundStyle(Color(hex: ctx.style.title))
        }
        .padding(.horizontal, 26)
        .padding(.vertical, 14)
        .background(Capsule().fill(Color(hex: ctx.style.chipFill)))
        .overlay(Capsule().strokeBorder(Color(hex: ctx.style.chipBorder), lineWidth: 2))
    }
}

/// Caption on top, one framed device below; optionally a row of language chips in between.
struct SingleLayout: View {
    let ctx: ShotContext
    let screen: CGImage
    var chips: [Chip] = []

    var body: some View {
        Artboard(ctx: ctx) {
            VStack(alignment: .leading, spacing: 0) {
                CaptionBlock(ctx: ctx)
                if !chips.isEmpty {
                    chipRows
                        .padding(.bottom, ctx.spec.subtitleSize)
                }
                GeometryReader { geo in
                    let size = DeviceGeometry.fitScreen(aspect: screen.aspect, in: geo.size, spec: ctx.spec, bezel: ctx.bezel)
                    DeviceFrame(spec: ctx.spec, bezel: ctx.bezel, screenSize: size) { s in
                        ScreenImage(image: screen, size: s)
                    }
                    .deviceShadow()
                    .frame(width: geo.size.width, alignment: .top)
                }
            }
        }
    }

    private var chipRows: some View {
        let perRow = 3
        let rows = stride(from: 0, to: chips.count, by: perRow).map { Array(chips[$0..<min($0 + perRow, chips.count)]) }
        return VStack(alignment: .leading, spacing: 18) {
            ForEach(rows.indices, id: \.self) { r in
                HStack(spacing: 18) {
                    ForEach(rows[r].indices, id: \.self) { c in
                        ChipView(chip: rows[r][c], ctx: ctx)
                    }
                }
            }
        }
    }
}

/// One device whose screen is the left half of one capture and the right half of another.
struct SplitLayout: View {
    let ctx: ShotContext
    let left: CGImage
    let right: CGImage

    var body: some View {
        Artboard(ctx: ctx) {
            VStack(alignment: .leading, spacing: 0) {
                CaptionBlock(ctx: ctx)
                GeometryReader { geo in
                    let size = DeviceGeometry.fitScreen(aspect: left.aspect, in: geo.size, spec: ctx.spec, bezel: ctx.bezel)
                    DeviceFrame(spec: ctx.spec, bezel: ctx.bezel, screenSize: size) { s in
                        ZStack {
                            ScreenImage(image: left, size: s)
                            ScreenImage(image: right, size: s)
                                .mask(alignment: .trailing) {
                                    Rectangle().frame(width: s.width / 2, height: s.height)
                                }
                            Rectangle()
                                .fill(Color(hex: ctx.style.background[0]))
                                .frame(width: ctx.layout.seam ?? 4, height: s.height)
                        }
                    }
                    .deviceShadow()
                    .frame(width: geo.size.width, alignment: .top)
                }
            }
        }
    }
}

/// Two smaller devices: one at the top right behind, one at the bottom left in front.
struct TwoOffsetLayout: View {
    let ctx: ShotContext
    let front: CGImage
    let back: CGImage

    var body: some View {
        Artboard(ctx: ctx) {
            VStack(alignment: .leading, spacing: 0) {
                CaptionBlock(ctx: ctx)
                GeometryReader { geo in
                    let full = DeviceGeometry.fitScreen(aspect: front.aspect, in: geo.size, spec: ctx.spec, bezel: ctx.bezel)
                    let k = ctx.layout.scale ?? 0.72
                    let size = CGSize(width: full.width * k, height: full.height * k)
                    let total = DeviceGeometry.totalSize(spec: ctx.spec, bezel: ctx.bezel, screenSize: size)
                    ZStack(alignment: .topLeading) {
                        DeviceFrame(spec: ctx.spec, bezel: ctx.bezel, screenSize: size) { s in
                            ScreenImage(image: back, size: s)
                        }
                        .deviceShadow()
                        .offset(x: geo.size.width - total.width, y: 0)
                        DeviceFrame(spec: ctx.spec, bezel: ctx.bezel, screenSize: size) { s in
                            ScreenImage(image: front, size: s)
                        }
                        .deviceShadow()
                        .offset(x: 0, y: geo.size.height - total.height)
                    }
                }
            }
        }
    }
}

/// Caption, a staircase of celebration cards (one per language), and a device rising from the bottom edge.
struct HeroLayout: View {
    let ctx: ShotContext
    let screen: CGImage
    let cards: [CGImage]
    let labels: [String]

    var body: some View {
        let spec = ctx.spec
        let step = spec.margin * 0.22
        let chipSize = spec.subtitleSize * 1.6
        let gap: CGFloat = 24
        let cardWidth = spec.contentWidth - CGFloat(cards.count - 1) * step - chipSize - gap
        Artboard(ctx: ctx, bleedBottom: true) {
            VStack(alignment: .leading, spacing: 0) {
                CaptionBlock(ctx: ctx)
                VStack(alignment: .leading, spacing: 20) {
                    ForEach(cards.indices, id: \.self) { i in
                        HStack(spacing: gap) {
                            Text(i < labels.count ? labels[i] : "")
                                .font(.system(size: chipSize * 0.52))
                                .foregroundStyle(Color(hex: ctx.style.accent))
                                .frame(width: chipSize, height: chipSize)
                                .background(Circle().fill(Color(hex: ctx.style.chipFill)))
                                .overlay(Circle().strokeBorder(Color(hex: ctx.style.chipBorder), lineWidth: 2))
                            Image(decorative: cards[i], scale: 1)
                                .resizable()
                                .interpolation(.high)
                                .aspectRatio(contentMode: .fit)
                                .frame(width: cardWidth)
                                .clipShape(RoundedRectangle(cornerRadius: 30 * cardWidth / CGFloat(cards[i].width), style: .continuous))
                                .shadow(color: .black.opacity(0.08), radius: 16, x: 0, y: 8)
                        }
                        .padding(.leading, CGFloat(i) * step)
                    }
                }
                .padding(.bottom, spec.subtitleSize)
                GeometryReader { geo in
                    let width = geo.size.width * (ctx.layout.deviceWidthFraction ?? 0.84)
                    let size = DeviceGeometry.screenSize(width: width, aspect: screen.aspect, bezel: ctx.bezel)
                    DeviceFrame(spec: spec, bezel: ctx.bezel, screenSize: size) { s in
                        ScreenImage(image: screen, size: s)
                    }
                    .deviceShadow()
                    .frame(width: geo.size.width, alignment: .top)
                }
            }
        }
    }
}

/// A device showing a plain wallpaper with the rendered widgets on it.
struct WidgetHomeLayout: View {
    let ctx: ShotContext
    let widgets: [(role: String, image: CGImage)]

    var body: some View {
        Artboard(ctx: ctx) {
            VStack(alignment: .leading, spacing: 0) {
                CaptionBlock(ctx: ctx)
                GeometryReader { geo in
                    let size = DeviceGeometry.fitScreen(aspect: ctx.spec.captureAspect, in: geo.size, spec: ctx.spec, bezel: ctx.bezel)
                    DeviceFrame(spec: ctx.spec, bezel: ctx.bezel, screenSize: size) { s in
                        homeScreen(size: s)
                    }
                    .deviceShadow()
                    .frame(width: geo.size.width, alignment: .top)
                }
            }
        }
    }

    private func homeScreen(size s: CGSize) -> some View {
        let widest = ctx.spec.widgetWidths.values.max() ?? 0.8
        return ZStack(alignment: .top) {
            LinearGradient(colors: ctx.style.wallpaper.map { Color(hex: $0) }, startPoint: .topLeading, endPoint: .bottomTrailing)
            statusBar(size: s)
            VStack(alignment: .leading, spacing: s.width * 0.045) {
                ForEach(widgets.indices, id: \.self) { i in
                    Image(decorative: widgets[i].image, scale: 1)
                        .resizable()
                        .interpolation(.high)
                        .aspectRatio(contentMode: .fit)
                        .frame(width: s.width * (ctx.spec.widgetWidths[widgets[i].role] ?? 0.5))
                        .shadow(color: .black.opacity(0.10), radius: 20, x: 0, y: 10)
                }
            }
            .frame(width: s.width * widest, alignment: .leading)
            .padding(.top, s.height * 0.115)
        }
    }

    private func statusBar(size s: CGSize) -> some View {
        HStack {
            Text("9:41")
                .font(.system(size: s.width * 0.04, weight: .semibold))
            Spacer()
            Image(systemName: "wifi")
            Image(systemName: "battery.100percent")
        }
        .font(.system(size: s.width * 0.036, weight: .semibold))
        .foregroundStyle(Color.white)
        .padding(.horizontal, s.width * 0.11)
        .padding(.top, s.height * 0.024)
    }
}

/// All outputs of one device and locale side by side, for review.
struct ContactSheet: View {
    let items: [(label: String, image: CGImage)]
    let columns: Int
    let cellWidth: CGFloat

    var body: some View {
        let rows = stride(from: 0, to: items.count, by: columns).map { Array(items[$0..<min($0 + columns, items.count)]) }
        VStack(alignment: .leading, spacing: 24) {
            ForEach(rows.indices, id: \.self) { r in
                HStack(alignment: .top, spacing: 24) {
                    ForEach(rows[r].indices, id: \.self) { c in
                        VStack(spacing: 8) {
                            Image(decorative: rows[r][c].image, scale: 1)
                                .resizable()
                                .interpolation(.high)
                                .aspectRatio(contentMode: .fit)
                                .frame(width: cellWidth)
                            Text(rows[r][c].label)
                                .font(.system(size: 18))
                                .foregroundStyle(Color.black)
                        }
                    }
                }
            }
        }
        .padding(24)
        .background(Color(white: 0.82))
        .environment(\.colorScheme, .light)
    }
}
