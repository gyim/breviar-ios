//
//  BRSettings.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import "BRSettings.h"

static BRSettings *_instance;

@implementation BRSettings

+ (BRSettings *)instance
{
    if (!_instance) {
        _instance = [[BRSettings alloc] init];
    }
    return _instance;
}

- (id)init {
    if (self = [super init]) {
        self.defaultOptions = [NSSet setWithObjects:
                               // Enable all prayer parts by default
                               @"of1c", @"of1s", @"of1r", @"of1o", @"of1t", @"of1pr",
                               nil];
        
        self.allOptions = [NSSet setWithObjects:
                           // Enabled prayer parts
                           @"of1c", @"of1s", @"of1r", @"of1o", @"of1t", @"of1pr",
                           nil];
    }
    return self;
}

- (NSString *)prayerFontFamily {
    NSString *value = [[NSUserDefaults standardUserDefaults] stringForKey:@"PrayerFontFamily"];
    return value ? value : @"Baskerville";
}

- (void)setPrayerFontFamily:(NSString *)prayerFontFamily {
    [[NSUserDefaults standardUserDefaults] setValue:prayerFontFamily forKey:@"PrayerFontFamily"];
}

- (NSInteger)prayerFontSize {
    NSInteger value = [[NSUserDefaults standardUserDefaults] integerForKey:@"PrayerFontSize"];
    return value ? value : 18;
}

- (void)setPrayerFontSize:(NSInteger)prayerFontSize {
    [[NSUserDefaults standardUserDefaults] setInteger:prayerFontSize forKey:@"PrayerFontSize"];
}

- (BOOL)boolOption:(NSString *)optionId {
    NSUserDefaults *settings = [NSUserDefaults standardUserDefaults];
    if ([settings objectForKey:optionId]) {
        return [settings boolForKey:optionId];
    }
    else {
        return [self.defaultOptions containsObject:optionId];
    }
}

- (void)setBoolOption:(NSString *)optionId value:(BOOL)value {
    [[NSUserDefaults standardUserDefaults] setBool:value forKey:optionId];
}

- (NSDictionary *)prayerQueryOptions {
    NSMutableDictionary *opts = [NSMutableDictionary dictionary];
    
    for (NSString *optionId in self.allOptions) {
        if ([self boolOption:optionId]) {
            [opts setObject:@"1" forKey:optionId];
        }
        else {
            [opts setObject:@"0" forKey:optionId];
        }
    }
    return opts;
}

@end
