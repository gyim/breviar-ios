//
//  main.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import <UIKit/UIKit.h>

#import "BRAppDelegate.h"

void set_ui_language()
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];

#ifdef BREVIAR_LANG
    #define xstr(s) str(s)
    #define str(s) #s
    NSString *contentLanguage = [NSString stringWithCString:xstr(BREVIAR_LANG) encoding:NSUTF8StringEncoding];
#else
    NSString *contentLanguage = [userDefaults stringForKey:@"j"];
#endif

    NSDictionary *uiLanguages = @{
        @"cz": @"cs",
        @"czop": @"cs",
        @"hu": @"hu",
        @"sk": @"sk",
    };

    if (contentLanguage) {
        NSString *uiLanguage = [uiLanguages objectForKey:contentLanguage];
        if (uiLanguage) {
            [userDefaults setObject:@[uiLanguage, @"en"] forKey:@"AppleLanguages"];
        }
    }
}

int main(int argc, char *argv[])
{
    @autoreleasepool {
        set_ui_language();
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([BRAppDelegate class]));
    }
}
