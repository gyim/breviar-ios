//
//  BRSettings.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import "BRSettings.h"
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
				NSObject *defaultValue = [option objectForKey:@"default"];
				
				[options setObject:option forKey:optionId];
				if (defaultValue != nil && ![userDefaults objectForKey:optionId]) {
					[userDefaults setObject:defaultValue forKey:optionId];
				}
			}
		}
		
		self.options = options;
		
		// Set default language by locale
		// (the block above already set a language, but we may override it)
		if (lang == nil) {
			NSLocale *locale = [NSLocale currentLocale];
			NSString *langCode = [locale objectForKey:NSLocaleLanguageCode];
			NSArray *supportedLangs = [self stringOptionsForOption:LANG_OPTION];
			if ([supportedLangs containsObject:langCode]) {
				[self setString:langCode forOption:LANG_OPTION];
			}
		}
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
}

- (BOOL)boolForOption:(NSString *)optionId {
	return [[NSUserDefaults standardUserDefaults] boolForKey:optionId];
}

- (void)setBool:(BOOL)value forOption:(NSString *)optionId {
	[[NSUserDefaults standardUserDefaults] setBool:value forKey:optionId];
}

- (UIFont *)fontForOption:(NSString *)optionId {
	NSDictionary *fontData = [[NSUserDefaults standardUserDefaults] dictionaryForKey:optionId];
	UIFont *font = [UIFont fontWithName:[fontData objectForKey:@"family"]
								   size:[[fontData objectForKey:@"size"] floatValue]];
	return font;
}

- (void)setFont:(UIFont *)value forOption:(NSString *)optionId {
	NSDictionary *fontData = @{
		@"family": value.fontName,
		@"size":[NSNumber numberWithInteger:value.pointSize]
	};
	[[NSUserDefaults standardUserDefaults] setObject:fontData forKey:optionId];
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
}

- (NSArray *)stringOptionsForOption:(NSString *)optionId {
	NSDictionary *option = [self.options objectForKey:optionId];
	return [option objectForKey:@"options"];
}

@end
