//
//  BRDay.m
//  Breviar
//
//  Created by Gyimesi Akos on 10/17/12.
//
//

#import "BRDay.h"
#import "BRCGIQuery.h"

@implementation BRDay

+(BRDay *)dayWithDate:(NSDate *)date {
	return [[BRDay alloc] initWithDate:date];
}

- (id)initWithDate:(NSDate *)date {
	if (self = [super init]) {
		// Get XML data for the day
		NSDateComponents *components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:date];
		NSString *dayData;
		dayData = [BRCGIQuery queryWithArgs:@{
				   @"qt": @"pxml",
				   @"d": [NSNumber numberWithInteger:components.day],
				   @"m": [NSNumber numberWithInteger:components.month],
				   @"r": [NSNumber numberWithInteger:components.year],
				   @"j": @"hu"
				   }];
		
		// Parse XML data (TODO)
		NSLog(@"XML data:\n%@", dayData);
	}
	return self;
}

@end
