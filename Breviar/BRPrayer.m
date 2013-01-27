//
//  BRPrayer.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayer.h"
#include "BRCGIQuery.h"
#include "BRSettings.h"

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

- (NSString *)title {
	return prayerTitles[self.prayerType];
}

- (NSString *)body {
	if (!body) {
		NSDateComponents *components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:self.date];
		
		NSMutableDictionary *queryOptions = [NSMutableDictionary dictionary];
		[queryOptions addEntriesFromDictionary:[BRSettings instance].prayerQueryOptions];
		[queryOptions addEntriesFromDictionary:@{
			 @"qt": @"pdt",
			 @"d": [NSNumber numberWithInteger:components.day],
			 @"m": [NSNumber numberWithInteger:components.month],
			 @"r": [NSNumber numberWithInteger:components.year],
			 @"p": prayerQueryIds[self.prayerType],
			 @"ds": [NSNumber numberWithInteger:self.celebrationId],
			 @"o0": @"60",
			 @"o2": @"152",
		 }];
		
		body = [BRCGIQuery queryWithArgs:queryOptions];
	}
	return body;
}

+ (BRPrayerType)prayerTypeFromQueryId:(NSString *)queryId {
	int i;
	for (i=BRInvitatory; i<=BRCompline; i++) {
		if ([prayerQueryIds[i] isEqualToString:queryId]) {
			return (BRPrayerType)i;
		}
	}
	return BRInvitatory;
}

@end
