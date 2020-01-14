//
//  BRCGIQuery.h
//  Breviar
//
//  Created by Gyimesi Akos on 10/17/12.
//
//

#import <Foundation/Foundation.h>

@interface BRCGIQuery : NSObject

+(NSString *)localQueryWithArgs:(NSDictionary *)args;
+(NSURLSessionTask *)remoteQueryWithArgs:(NSDictionary *)args completionHandler:(void (^)(NSString *result, NSError *error))completionHandler;

@end
