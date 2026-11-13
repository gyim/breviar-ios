import Foundation

let root = URL(fileURLWithPath: CommandLine.arguments.count > 1 ? CommandLine.arguments[1] : FileManager.default.currentDirectoryPath)
let data = try Data(contentsOf: root.appendingPathComponent("Breviar.xcodeproj/project.pbxproj"))
let project = try PropertyListSerialization.propertyList(from: data, options: [], format: nil) as! [String: Any]
let objects = project["objects"] as! [String: [String: Any]]
let rootObject = objects[project["rootObject"] as! String]!
var paths: [String: URL] = [:]
func walk(_ id: String, parent: URL) {
    guard let object = objects[id] else { fatalError("Missing project object \(id)") }
    let base = object["sourceTree"] as? String == "SOURCE_ROOT" ? root : parent
    let path = (object["path"] as? String).map { base.appendingPathComponent($0) } ?? base
    if let children = object["children"] as? [String] {
        for child in children { walk(child, parent: path) }
    } else if object["isa"] as? String == "PBXFileReference" { paths[id] = path.standardizedFileURL }
}
walk(rootObject["mainGroup"] as! String, parent: root)
let wanted: Set<String> = ["SharedPrayerLink.swift", "SharedPrayerSession.swift", "ReaderAppearance.swift", "PrayerSharing.swift"]
let app = objects.values.first { $0["isa"] as? String == "PBXNativeTarget" && $0["name"] as? String == "Breviar" }!
let appSources = (app["buildPhases"] as! [String]).compactMap { objects[$0] }
    .filter { $0["isa"] as? String == "PBXSourcesBuildPhase" }
let sourceIDs = appSources.flatMap { $0["files"] as? [String] ?? [] }
    .compactMap { objects[$0]?["fileRef"] as? String }
let appSourceFiles = Set(appSources.flatMap { $0["files"] as? [String] ?? [] })
let otherSourceIDs = objects.values.filter { $0["isa"] as? String == "PBXSourcesBuildPhase" }
    .flatMap { $0["files"] as? [String] ?? [] }.filter { !appSourceFiles.contains($0) }
    .compactMap { objects[$0]?["fileRef"] as? String }
for name in wanted {
    let matches = paths.filter { $0.value.lastPathComponent == name }
    precondition(matches.count == 1, "Missing or duplicate source reference: \(name)")
    let entry = matches.first!
    precondition(FileManager.default.fileExists(atPath: entry.value.path), "Wrong source path: \(entry.value.path)")
    precondition(sourceIDs.contains(entry.key), "Uncompiled app source: \(name)")
    precondition(!otherSourceIDs.contains(entry.key), "Sharing source should not be in a widget: \(name)")
}
let entitlements = try Data(contentsOf: root.appendingPathComponent("Breviar/Breviar.entitlements"))
let values = try PropertyListSerialization.propertyList(from: entitlements, options: [], format: nil) as! [String: Any]
precondition((values["com.apple.developer.associated-domains"] as? [String]) == ["applinks:breviar.sk"])
print("Xcode source references and Associated Domains entitlement verified")
