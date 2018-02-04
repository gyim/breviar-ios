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

@implementation BRCGIQuery

+(NSString *)queryWithArgs:(NSDictionary *)args {
	NSMutableString *queryString = [[NSMutableString alloc] init];
	NSMutableString *result = [[NSMutableString alloc] init];
    
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
		[result appendFormat:@"%@=%@<br>", key, [args objectForKey:key]];
#endif
		
		if (i++ == 0) {
			[queryString appendFormat:@"-s%@=%@", key, [args objectForKey:key]];
		}
		else {
			[queryString appendFormat:@"&%@=%@", key, [args objectForKey:key]];
		}
	}

	// Include directory
	NSString *includeString = [NSString stringWithFormat:@"-i%@",
							   [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"html/include"]];
	
	int argc = 5;
	const char *argv[] = {
		SCRIPT_NAME,
		"-qpdt",
		"-H",
		queryString.UTF8String,
		includeString.UTF8String
	};
	
	@synchronized ([BRCGIQuery class]) {
		breviar_main(argc, (char **)argv);

		NSString *prayerBody = [NSString stringWithCString:getExportedString() encoding:NSUTF8StringEncoding];
		[result appendString:prayerBody];
	}
	return result;
}

@end
