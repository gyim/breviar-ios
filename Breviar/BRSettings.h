//
//  BRSettings.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import <Foundation/Foundation.h>

@interface BRSettings : NSObject

@property(strong) NSSet *defaultOptions;
@property(strong) NSSet *allOptions;
@property(readonly) NSDictionary *prayerQueryOptions;

@property NSString *prayerFontFamily;
@property NSInteger prayerFontSize;

+ (BRSettings *)instance;

- (BOOL)boolOption:(NSString *)optionId;
- (void)setBoolOption:(NSString *)optionId value:(BOOL)value;

@end
