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

@end
