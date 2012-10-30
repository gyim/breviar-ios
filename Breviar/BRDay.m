//
//  BRDay.m
//  Breviar
//
//  Created by Gyimesi Akos on 10/17/12.
//
//

#import "BRDay.h"
#import "BRCGIQuery.h"
#import "RaptureXML/RXMLElement.h"

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
                   @"j": @"hu",
                   }];
        
        // Find XML header
        NSRange r = [dayData rangeOfString:@"<?xml"];
        if (r.location != NSNotFound) {
            dayData = [dayData substringFromIndex:r.location];
        }
        dayData = [dayData stringByAppendingString:@"</LHData>"]; // HACK
        
        // Parse XML data
        RXMLElement *xml = [RXMLElement elementFromXMLString:dayData encoding:NSWindowsCP1250StringEncoding];
        NSMutableArray *celebrations = [NSMutableArray array];
        
        [xml iterate:@"CalendarDay.Celebration" usingBlock:^(RXMLElement *celebrationXml) {
            BRCelebration *celebration = [[BRCelebration alloc] init];
            celebration.celebrationId = [celebrationXml attributeAsInt:@"Id"];
            
            // TODO: turn HTML code into separate XML elements
            [celebrationXml iterate:@"StringTitle.span" usingBlock:^(RXMLElement *node) {
                NSString *value = node.description;
                if (!celebration.title)
                    celebration.title = value;
                else
                    celebration.subtitle = value;
            }];
            [celebrations addObject:celebration];
        }];
        
        self.celebrations = [NSArray arrayWithArray:celebrations];
    }
    return self;
}

@end
