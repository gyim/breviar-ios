//
//  BRPrayer.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayer.h"
#include "BRCGIQuery.h"

@implementation BRPrayer
@synthesize prayerType;
@synthesize title;
@synthesize body;

static NSString *prayerTitles[] = {
	[BRInvitatory]         = @"Invitatory",
	[BROfficeOfReadings]   = @"Office of Readings",
	[BRMorningPrayer]      = @"Morning Prayer",
	[BRMidMorningPrayer]   = @"Mid-Morning Prayer",
	[BRMiddayPrayer]       = @"Midday Prayer",
	[BRMidAfternoonPrayer] = @"Mid-Afternoon Prayer",
	[BREveningPrayer]      = @"Evening Prayer",
	[BRCompline]           = @"Compline"
};

static NSString *prayerQueryIds[] = {
	[BRInvitatory]         = @"mi",
	[BROfficeOfReadings]   = @"mpc",
	[BRMorningPrayer]      = @"mrch",
	[BRMidMorningPrayer]   = @"mpred",
	[BRMiddayPrayer]       = @"mna",
	[BRMidAfternoonPrayer] = @"mpo",
	[BREveningPrayer]      = @"mv",
	[BRCompline]           = @"mk"
};

+ (BRPrayer *)prayerWithType:(BRPrayerType)prayerType celebration:(NSInteger)celebrationId date:(NSDate *)date {
	BRPrayer *prayer = [[BRPrayer alloc] init];
	prayer.title = prayerTitles[prayerType];
	
	// Get date components
	NSDateComponents *components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:date];
	
	prayer.body = [BRCGIQuery queryWithArgs:@{
				   @"qt": @"pdt",
				   @"d": [NSNumber numberWithInteger:components.day],
				   @"m": [NSNumber numberWithInteger:components.month],
				   @"r": [NSNumber numberWithInteger:components.year],
				   @"p": prayerQueryIds[prayerType],
				   @"ds": [NSNumber numberWithInteger:celebrationId],
				   @"o0": @"60",
				   @"o2": @"152",
				   }];
	
	return prayer;
}

@end
