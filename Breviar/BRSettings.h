//
//  BRSettings.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define BR_MIN_FONT_SIZE 12
#define BR_MAX_FONT_SIZE 30

@interface BRSettings : NSObject

@property(strong) NSArray *sections;
@property(strong) NSDictionary *options;

@property(readonly) NSDictionary *prayerQueryOptions;

@property NSString *prayerFontFamily;
@property NSInteger prayerFontSize;

+ (BRSettings *)instance;

- (BOOL)boolForOption:(NSString *)optionId;
- (void)setBool:(BOOL)value forOption:(NSString *)optionId;

- (NSString *)fontFamilyForOption:(NSString *)optionId;
- (NSInteger)fontSizeForOption:(NSString *)optionId;
- (void)setFontFamily:(NSString *)familyName size:(NSInteger)size forOption:(NSString *)optionId;

- (NSString *)stringForOption:(NSString *)optionId;
- (void)setString:(NSString *)value forOption:(NSString *)optionId;
- (NSArray *)stringOptionsForOption:(NSString *)optionId;

- (BOOL)evaluatePredicate:(NSString *)predicate;

@end
