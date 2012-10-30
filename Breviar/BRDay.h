//
//  BRDay.h
//  Breviar
//
//  Created by Gyimesi Akos on 10/17/12.
//
//

#import <Foundation/Foundation.h>
#import "BRCelebration.h"
#import "BRPrayer.h"

@interface BRDay : NSObject

@property(strong) NSDate *date;
@property(strong) NSArray *celebrations;

+(BRDay *)dayWithDate:(NSDate *)date;

@end
