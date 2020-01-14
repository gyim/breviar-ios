//
//  BRSettings.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import "BRSettings.h"
#import "BRUtil.h"
#import "BRFontHelper.h"

#define LANG_OPTION @"j"

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
        NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
        NSString *lang = [userDefaults stringForKey:LANG_OPTION];
        
        // Load settings from Settings.plist and fill default values
        NSDictionary *settingsDescriptor = [NSDictionary dictionaryWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"Settings" ofType:@"plist"]];
        
        self.sections = [settingsDescriptor objectForKey:@"sections"];
        NSMutableDictionary *options = [[NSMutableDictionary alloc] init];
        
        for (NSDictionary *section in self.sections) {
            for (NSDictionary *option in [section objectForKey:@"items"]) {
                NSString *optionId = [option objectForKey:@"id"];
                [options setObject:option forKey:optionId];

                NSObject *defaultValue = [option objectForKey:@"default"];
                if (defaultValue != nil && ![userDefaults objectForKey:optionId]) {
                    [userDefaults setObject:defaultValue forKey:optionId];
                }
            }
        }
        
        // Set default language by locale
        // (the block above already set a language, but we may override it)
        if (lang == nil) {
#ifdef BREVIAR_LANG
#define xstr(s) str(s)
#define str(s) #s
            [self setString:[NSString stringWithCString:xstr(BREVIAR_LANG) encoding:NSUTF8StringEncoding] forOption:LANG_OPTION];
            [self setBool:NO forOption:@"multiLang"];
#else
            [self setBool:YES forOption:@"multiLang"];
            
            NSArray *supportedLanguages = [self stringOptionsForOption:LANG_OPTION];
            NSLocale *locale = [NSLocale currentLocale];
            
            NSString *preferredLanguage = [[NSLocale preferredLanguages] objectAtIndex:0];
            NSString *languageCode = [locale objectForKey:NSLocaleLanguageCode];
            NSString *countryCode = [[locale objectForKey:NSLocaleCountryCode] lowercaseString];
            
            // Workaround for Czech language code
            if ([preferredLanguage isEqualToString:@"cs"]) {
                preferredLanguage = @"cz";
            }
            if ([languageCode isEqualToString:@"cs"]) {
                languageCode = @"cz";
            }
            
            // Choose language
            if ([supportedLanguages containsObject:preferredLanguage]) {
                [self setString:preferredLanguage forOption:LANG_OPTION];
            }
            else if ([supportedLanguages containsObject:languageCode]) {
                [self setString:languageCode forOption:LANG_OPTION];
            }
            else if ([supportedLanguages containsObject:countryCode]) {
                [self setString:countryCode forOption:LANG_OPTION];
            }
#endif
        }
        
        // Set the conditional defaults after all other settings are loaded
        for (NSDictionary *section in self.sections) {
            for (NSDictionary *option in [section objectForKey:@"items"]) {
                NSString *optionId = [option objectForKey:@"id"];
                
                if ([option objectForKey:@"defaultCond"]) {
                    NSDictionary *predicates = [option objectForKey:@"defaultCond"];
                    NSObject *defaultValue = nil;
                    
                    for (NSString *predicate in predicates) {
                        if ([self evaluatePredicate:predicate]) {
                            defaultValue = [predicates objectForKey:predicate];
                            break;
                        }
                    }

                    if (defaultValue != nil && ![userDefaults objectForKey:optionId]) {
                        [userDefaults setObject:defaultValue forKey:optionId];
                    }
                }
            }
        }
        
        self.options = options;
        
        [userDefaults synchronize];
    }
    
    return self;
}

- (NSString *)prayerFontFamily {
    NSDictionary *font = [[NSUserDefaults standardUserDefaults] dictionaryForKey:@"prayerFont"];
    return [font objectForKey:@"family"];
}

- (void)setPrayerFontFamily:(NSString *)prayerFontFamily {
    NSMutableDictionary *font = [[[NSUserDefaults standardUserDefaults] dictionaryForKey:@"prayerFont"] mutableCopy];
    [font setObject:prayerFontFamily forKey:@"family"];
    [[NSUserDefaults standardUserDefaults] setObject:font forKey:@"prayerFont"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSInteger)prayerFontSize {
    NSDictionary *font = [[NSUserDefaults standardUserDefaults] dictionaryForKey:@"prayerFont"];
    NSNumber *fontSize = [font objectForKey:@"size"];
    return [fontSize intValue];
}

- (void)setPrayerFontSize:(NSInteger)prayerFontSize {
    NSMutableDictionary *font = [[[NSUserDefaults standardUserDefaults] dictionaryForKey:@"prayerFont"] mutableCopy];
    [font setObject:[NSNumber numberWithInteger:prayerFontSize] forKey:@"size"];
    [[NSUserDefaults standardUserDefaults] setObject:font forKey:@"prayerFont"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (BOOL)boolForOption:(NSString *)optionId {
    return [[NSUserDefaults standardUserDefaults] boolForKey:optionId];
}

- (void)setBool:(BOOL)value forOption:(NSString *)optionId {
    [[NSUserDefaults standardUserDefaults] setBool:value forKey:optionId];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)fontFamilyForOption:(NSString *)optionId {
    NSDictionary *fontData = [[NSUserDefaults standardUserDefaults] dictionaryForKey:optionId];
    return [fontData objectForKey:@"family"];
}

- (NSInteger)fontSizeForOption:(NSString *)optionId {
    NSDictionary *fontData = [[NSUserDefaults standardUserDefaults] dictionaryForKey:optionId];
    return [[fontData objectForKey:@"size"] integerValue];
}

- (void)setFontFamily:(NSString *)familyName size:(NSInteger)size forOption:(NSString *)optionId {
    NSDictionary *fontData = @{
        @"family": familyName,
        @"size": @(size)
    };
    [[NSUserDefaults standardUserDefaults] setObject:fontData forKey:optionId];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSDictionary *)prayerQueryOptions {
    NSMutableDictionary *queryOptions = [NSMutableDictionary dictionary];
    for (NSString *optionId in self.options) {
        NSDictionary *option = [self.options objectForKey:optionId];
        NSNumber *inPrayerQuery = [option objectForKey:@"inPrayerQuery"];
        if (inPrayerQuery == nil || [inPrayerQuery boolValue] == YES) {
            NSObject *value = [[NSUserDefaults standardUserDefaults] objectForKey:optionId];
            [queryOptions setObject:value.description forKey:optionId];
        }
    }
    return queryOptions;
}

- (NSString *)stringForOption:(NSString *)optionId {
    return [[NSUserDefaults standardUserDefaults] stringForKey:optionId];
}

- (void)setString:(NSString *)value forOption:(NSString *)optionId {
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:optionId];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSArray *)stringOptionsForOption:(NSString *)optionId {
    NSDictionary *option = [self.options objectForKey:optionId];
    return [option objectForKey:@"options"];
}

- (id)valueForKey:(NSString *)key {
    return [[NSUserDefaults standardUserDefaults] valueForKey:key];
}

- (BOOL)evaluatePredicate:(NSString *)predicate {
    if (predicate == nil) {
        return YES;
    } else if ([predicate isEqualToString:@"iPhone"]) {
        return UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone;
    } else if ([predicate isEqualToString:@"iPad"]) {
        return UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad;
    } else {
        NSPredicate *pred = [NSPredicate predicateWithFormat:predicate];
        return [pred evaluateWithObject:self];
    }
}

@end
