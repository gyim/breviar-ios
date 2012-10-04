//
//  BRPrayer.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayer.h"
#include "breviar.h"
#include "myexpt.h"

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

+ (BRPrayer *)prayerWithType:(BRPrayerType)prayerType date:(NSDate *)date {
	BRPrayer *prayer = [[BRPrayer alloc] init];
	prayer.title = prayerTitles[prayerType];
	
	// Get date components
	NSDateComponents *components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:date];
	
	// Generate body
	NSString *queryString = [NSString stringWithFormat:@"-sqt=pdt&d=%d&m=%d&r=%d&p=%@&ds=1&j=hu&o0=60&o2=152",
							 components.day,
							 components.month,
							 components.year,
							 prayerQueryIds[prayerType]];
	
	NSString *includeString = [NSString stringWithFormat:@"-i%@",
							   [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"html/include"]];
	
	int argc = 5;
	const char *argv[] = {
		"l.cgi",
		"-qpdt",
		"-H",
		queryString.UTF8String,
		includeString.UTF8String
	};
	breviar_main(argc, (char **)argv);
	
	prayer.body = [NSString stringWithCString:getExportedString() encoding:NSWindowsCP1250StringEncoding];
	
	return prayer;
}

@end
