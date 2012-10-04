//
//  BRSettings.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import <Foundation/Foundation.h>

@interface BRSettings : NSObject

@property NSString *prayerFontFamily;
@property NSInteger prayerFontSize;

+ (BRSettings *)instance;

@end
