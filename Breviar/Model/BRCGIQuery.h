//
//  BRCGIQuery.h
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 06. 23..
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRCGIQuery : NSObject
+(NSData *)queryWithArgs:(NSString *)args;
@end

NS_ASSUME_NONNULL_END
