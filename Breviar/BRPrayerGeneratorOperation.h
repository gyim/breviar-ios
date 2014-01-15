//
//  BRPrayerGeneratorOperation.h
//  Breviar
//
//  Created by Oto Kominak on 15.01.14.
//
//

#import <Foundation/Foundation.h>

@class BRDay;

@interface BRPrayerGeneratorOperation : NSOperation

- (id)initWithDay:(BRDay *)day;

@end
