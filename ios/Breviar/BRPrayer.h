//
//  BRPrayer.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import <Foundation/Foundation.h>

typedef enum {
	BRInvitatory = 0,
	BROfficeOfReadings,
	BRMorningPrayer,
	BRMidMorningPrayer,
	BRMiddayPrayer,
	BRMidAfternoonPrayer,
	BREveningPrayer,
	BRCompline
} BRPrayerType;

@interface BRPrayer : NSObject

@property BRPrayerType prayerType;
@property(strong) NSString *title;
@property(strong) NSString *body;

+ (BRPrayer *)prayerWithType:(BRPrayerType)prayerType date:(NSDate *)date;
@end
