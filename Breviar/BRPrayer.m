//
//  BRPrayer.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayer.h"
#import "BRCGIQuery.h"
#import "BRSettings.h"
#import "BRUtil.h"

static NSString *prayerQueryIds[] = {
    [BRInvitatory]         = @"mi",
    [BROfficeOfReadings]   = @"mpc",
    [BRMorningPrayer]      = @"mrch",
    [BRMidMorningPrayer]   = @"mpred",
    [BRMiddayPrayer]       = @"mna",
    [BRMidAfternoonPrayer] = @"mpo",
    [BREveningPrayer]      = @"mv",
    [BRCompline]           = @"mk",
    [BRStaticText]         = @"st",
};

static NSString *prayerNames[] = {
    [BRInvitatory]         = @"Invitatory",
    [BROfficeOfReadings]   = @"Readings",
    [BRMorningPrayer]      = @"Laudes",
    [BRMidMorningPrayer]   = @"Tertia",
    [BRMiddayPrayer]       = @"Sexta",
    [BRMidAfternoonPrayer] = @"Nona",
    [BREveningPrayer]      = @"Vespers",
    [BRCompline]           = @"Compline",
    [BRStaticText]         = @"Static Text",
};

@implementation BRPrayer

@synthesize
    body = _body,
    bodyForSpeechSynthesis = _bodyForSpeechSynthesis,
    extraOpts = _extraOpts;

- (NSString *)title {
    if (self.prayerType == BRStaticText) {
        return BREVIAR_STR(self.staticTextId);
    } else {
        return BREVIAR_STR(prayerQueryIds[self.prayerType]);
    }
}

- (NSString *)prayerName {
    return prayerNames[self.prayerType];
}

- (NSString *)queryId {
    return prayerQueryIds[self.prayerType];
}

- (NSString *)body {
    @synchronized (self) {
        if (!_body) {
            NSDictionary *queryOptions = [self getQueryOptions:nil];
            _body = [BRCGIQuery localQueryWithArgs:queryOptions];
        }
        return _body;
    }
}

- (NSString *)bodyForSpeechSynthesis
{
    @synchronized (self) {
        if (!_bodyForSpeechSynthesis) {
            NSDictionary *queryOptions = [self getQueryOptions:@{ @"of0bf": @YES }];
            _bodyForSpeechSynthesis = [BRCGIQuery localQueryWithArgs:queryOptions];
        }
        return _bodyForSpeechSynthesis;
    }
}

- (void)fetchBodyFromServer {
    NSDictionary *queryOptions = [self getQueryOptions:nil];
    [BRCGIQuery remoteQueryWithArgs:queryOptions completionHandler:^(NSString *result, NSError *error) {
        if (result) {
            @synchronized (self) {
                _body = result;
            }
        } else {
            NSLog(@"Error getting prayer body: %@", error);
            [self body];
        }
    }];
}

- (void)fetchSpeechSynthesisBodyFromServer {
    NSDictionary *queryOptions = [self getQueryOptions:@{ @"of0bf": @YES }];
    [BRCGIQuery remoteQueryWithArgs:queryOptions completionHandler:^(NSString *result, NSError *error) {
        if (result) {
            @synchronized (self) {
                _bodyForSpeechSynthesis = result;
            }
        } else {
            NSLog(@"Error getting prayer body: %@", error);
            [self bodyForSpeechSynthesis];
        }
    }];
}

- (void)refreshText;
{
    _body = nil;
    [self body];
}

- (NSDictionary *)getQueryOptions:(NSDictionary *)overwritingOptions {
    NSMutableDictionary *queryOptions = [NSMutableDictionary dictionary];
    
    if (self.prayerType == BRStaticText) {
        [queryOptions addEntriesFromDictionary:[BRSettings instance].prayerQueryOptions];
        [queryOptions addEntriesFromDictionary:@{
                                                 @"qt": @"pst",
                                                 @"st": self.staticTextId,
                                                 @"o0": @"64",
                                                 @"o1": @"5376",
                                                 @"o2": @"16512",
                                                 @"o3": @"1",
                                                 @"o4": @"0",
                                                 @"o5": @"8194"
                                                 }];
    } else if ([_extraOpts count]) {
        [queryOptions addEntriesFromDictionary:_extraOpts];
    } else {
        NSDateComponents *components = [[NSCalendar currentCalendar] components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear fromDate:self.date];
        
        [queryOptions addEntriesFromDictionary:[BRSettings instance].prayerQueryOptions];
        [queryOptions addEntriesFromDictionary:@{
                                                 @"qt": @"pdt",
                                                 @"d": [NSNumber numberWithInteger:components.day],
                                                 @"m": [NSNumber numberWithInteger:components.month],
                                                 @"r": [NSNumber numberWithInteger:components.year],
                                                 @"p": prayerQueryIds[self.prayerType],
                                                 @"ds": [NSNumber numberWithInteger:self.celebrationId],
                                                 @"o0": @"65",
                                                 @"o1": @"5440",
                                                 @"o2": @"16384",
                                                 @"o3": @"0",
                                                 @"o4": @"0",
                                                 @"o5": @"0"
                                                 }];
    }
    if (overwritingOptions) {
        [queryOptions addEntriesFromDictionary:overwritingOptions];
    }
    return queryOptions;
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

+ (NSString *)queryIdFromPrayerType:(BRPrayerType)prayerType {
    return prayerQueryIds[prayerType];
}

+ (BRPrayer *)prayerForStaticTextId:(NSString *)staticTextId {
    BRPrayer *prayer = [[BRPrayer alloc] init];
    prayer.prayerType = BRStaticText;
    prayer.staticTextId = staticTextId;
    return prayer;
}

@end
