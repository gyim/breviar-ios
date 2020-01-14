//
//  BRCGIQuery.m
//  Breviar
//
//  Created by Gyimesi Akos on 10/17/12.
//
//

#import "BRCGIQuery.h"
#import "BRUtil.h"
#include "breviar.h"
#include "myexpt.h"

#define REMOTE_CGI_URL @"https://lh.kbs.sk/cgi-bin/l.cgi"

@implementation BRCGIQuery

+(NSString *)queryStringForArgs:(NSDictionary *)args {
    NSMutableString *queryString = [[NSMutableString alloc] init];
    
    // Fix for Common Parts: transpose parameter value by +1
    if (args[@"of3"] && [args[@"of3"] isKindOfClass:[NSString class]]) {
        NSString *of3Value = args[@"of3"];

        NSMutableDictionary *mutableArgs = [NSMutableDictionary dictionaryWithDictionary:args];
        mutableArgs[@"of3"] = [NSString stringWithFormat:@"%d", [of3Value intValue] + 1];
        args = [NSDictionary dictionaryWithDictionary:mutableArgs];
    }
    
    // Generate query string
    int i=0;
    for (NSString *key in args) {
#if DEBUG_SETTINGS
        NSLog(@"%@=%@", key, [args objectForKey:key]);
#endif
        
        if (i++ == 0) {
            [queryString appendFormat:@"%@=%@", key, [args objectForKey:key]];
        }
        else {
            [queryString appendFormat:@"&%@=%@", key, [args objectForKey:key]];
        }
    }
    return queryString;
}

+(NSString *)localQueryWithArgs:(NSDictionary *)args {
    NSString *queryString = [BRCGIQuery queryStringForArgs:args];

	// Include directory
	NSString *includeString = [NSString stringWithFormat:@"-i%@",
							   [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"html/include"]];
	
	int argc = 5;
	const char *argv[] = {
		SCRIPT_NAME,
		"-qpdt",
		"-H",
		[NSString stringWithFormat:@"-s%@", queryString].UTF8String,
		includeString.UTF8String
	};
	
	@synchronized ([BRCGIQuery class]) {
		breviar_main(argc, (const char **)argv);
		return [NSString stringWithCString:getExportedString() encoding:NSUTF8StringEncoding];
	}
}

+(NSURLSessionTask *)remoteQueryWithArgs:(NSDictionary *)args completionHandler:(void (^)(NSString *result, NSError *error))completionHandler {
    NSString *queryString = [BRCGIQuery queryStringForArgs:args];
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"%@?%@", REMOTE_CGI_URL, queryString]];
    
    NSURLSessionTask *task = [[NSURLSession sharedSession] dataTaskWithURL:url completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            completionHandler(nil, error);
        } else {
            NSString *result = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            completionHandler(result, nil);
        }
    }];
    [task resume];
    return task;
}

@end
