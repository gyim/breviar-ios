//
//  MainScreen.swift
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 06..
//

import SwiftUI

struct MainScreen: View {
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        NavigationView{
            MainScreenContent()
            .navigationTitle("Today")
            .navigationBarItems(
                leading: Button(action: {}, label: {Label("", systemImage: "calendar")})
            )
            .toolbar {
                HStack{
                    Button(action: {}, label: {Label("Previous Day", systemImage: "chevron.left")})
                        .padding()
                    Spacer()
                        .frame(width: 6.0)
                    Button(action: {}, label: {Label("Next Day", systemImage: "chevron.right")})
                }
            }
        }
        .navigationViewStyle(StackNavigationViewStyle())
    }
}

struct MainScreenContent: View {
    @EnvironmentObject var model: BreviarModel
    
    var body: some View {
        switch model.dayState {
        case .idle, .loading:
            Text("Loading...")
        case .failed(let error):
            Text(error.localizedDescription)
        case .loaded(let day):
            List{
                Section() {
                    ForEach(0..<day.celebrations.count) { i in
                        let celebration = day.celebrations[i]
                        CelebrationRow(celebration: celebration, checked: (model.celebrationIndex == i))
                            .onTapGesture {
                                withAnimation {
                                    model.celebrationIndex = i
                                }
                            }
                    }
                }

                Section(header: Text("Prayers")) {
                    PrayerLink(label: "Invitatory", icon: "sparkles")
                    PrayerLink(label: "Office of Readings", icon: "text.book.closed")
                    PrayerLink(label: "Morning Prayer", icon: "sunrise")
                    PrayerLink(label: "Mid-Morning Prayer", icon: "sun.min")
                    PrayerLink(label: "Midday Prayer", icon: "sun.max.fill")
                    PrayerLink(label: "Mid-Afternoon Prayer", icon: "sun.min.fill")
                    PrayerLink(label: "Evening Prayer", icon: "sunset.fill")
                    PrayerLink(label: "Compline", icon: "moon.stars.fill")
                }
            }
        }
    }
}

struct CelebrationColorShape : Shape {
    var color: LiturgicalColor
    var width: CGFloat
    
    func path(in rect: CGRect) -> Path {
        var path = Path()
        path.addRect(CGRect(x: rect.minX, y: rect.minY, width: width, height: rect.height))
        return path
    }
}

struct CelebrationColorView : View {
    var color: LiturgicalColor
    var width: CGFloat
    
    var body: some View {
        VStack(spacing: 0){
            CelebrationColorShape(color: color, width: width)
                .foregroundColor(uiColors[color.firstColor()])
            CelebrationColorShape(color: color, width: width)
                .foregroundColor(uiColors[color.secondColor()])
        }
    }
    
    let uiColors: [LiturgicalColor: Color] = [
        .red: Color(.sRGB, red: 0xed/255, green: 0x2f/255, blue: 0x29/255, opacity: 1),
        .white: Color(.sRGB, red: 0xe0/255, green: 0xe0/255, blue: 0xe0/255, opacity: 1),
        .green: Color(.sRGB, red: 0x6f/255, green: 0xcf/255, blue: 0x85/255, opacity: 1),
        .violet: Color(.sRGB, red: 0x96/255, green: 0x24/255, blue: 0xc7/255, opacity: 1),
        .rose: Color(.sRGB, red: 0xff/255, green: 0x8b/255, blue: 0xed/255, opacity: 1),
        .black: Color(.sRGB, red: 0x4e/255, green: 0x4e/255, blue: 0x4e/255, opacity: 1),
    ]
}

struct CelebrationRow : View {
    var celebration: Celebration
    var checked: Bool

    var body: some View {
        HStack{
            VStack{
                HStack{
                    Text(celebration.title)
                        .bold()
                    Spacer()
                }
                HStack{
                    Text(celebration.subtitle)
                        .font(.system(size: 14))
                        .foregroundColor(.secondary)
                    Spacer()
                }
            }
            .padding(EdgeInsets(top: 0, leading: 15, bottom: 0, trailing: 0))
            .overlay(CelebrationColorView(color: celebration.liturgicalColor, width: 10))
            
            Image(systemName: "checkmark").resizable().frame(width: 20, height: 20)
                .foregroundColor(.blue)
                .padding(5)
                .opacity(checked ? 1 : 0)
        }
    }
}

struct PrayerLink: View {
    var label: String
    var icon: String
    
    var body: some View {
        NavigationLink(
            destination: Text(label)) {
            Label(label, systemImage: icon)
        }
    }
}

struct MainScreen_Previews: PreviewProvider {
    static var previews: some View {
        let model = BreviarModel(dataSource: TestDataSource())
        MainScreen().environmentObject(model.load())
    }
}
