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
    BRCompline,
    BRStaticText
} BRPrayerType;

@interface BRPrayer : NSObject

@property BRPrayerType prayerType;
@property(strong) NSDate *date;
@property NSInteger celebrationId;
@property(readonly) NSString *title;
@property(readonly) NSString *prayerName;
@property(readonly) NSString *queryId;
@property(readonly) NSString *body;
@property(readonly) NSString *bodyForSpeechSynthesis;
@property(assign) CGFloat scrollOffset;
@property(strong) NSString *staticTextId;

+ (BRPrayerType)prayerTypeFromQueryId:(NSString *)queryId;
+ (NSString *)queryIdFromPrayerType:(BRPrayerType)prayerType;
+ (BRPrayer *)prayerForStaticTextId:(NSString *)staticTextId;

@end
