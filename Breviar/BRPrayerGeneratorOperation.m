//
//  BRPrayerGeneratorOperation.m
//  Breviar
//
//  Created by Oto Kominak on 15.01.14.
//
//

#import "BRPrayerGeneratorOperation.h"
#import "BRDay.h"
#import "BRCelebration.h"
#import "BRPrayer.h"


@interface BRPrayerGeneratorOperation ()

@property (strong) BRDay *day;

@end

@implementation BRPrayerGeneratorOperation

- (id)initWithDay:(BRDay *)day {
    self = [super init];
    if (self) {
        self.day = day;
    }
    return self;
}

- (void)main {
    @autoreleasepool {
        @synchronized (self.day) {
            for (BRCelebration *celebration in self.day.celebrations) {
                for (BRPrayer *prayer in celebration.prayers) {
                    if (self.isCancelled) {
//                        NSLog(@"CANCEL**** %@", celebration.title);
                        return;
                    }
//                    NSLog(@"Generating %@ / %@", celebration.title, prayer.title);
                    __unused NSString *body = prayer.body;
                }
            }
        }
    }
}

@end
