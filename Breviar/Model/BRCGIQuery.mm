//
//  BRCGIQuery.mm
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 06. 23..
//

#import "BRCGIQuery.h"
#include "breviar.h"
#include "myexpt.h"

@implementation BRCGIQuery

+(NSData *)queryWithArgs:(NSString *)args {
    // Generate query string
    NSString *queryString = [NSString stringWithFormat:@"-s%@", args];

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
        breviar_main(argc, (const char **)argv);

        char *result = getExportedString();
        
        // Workaround: remove data before <?xml tag
        char *xmlTag = strstr(result, "<?xml");
        if (xmlTag) {
            result = xmlTag;
        }
        
        NSMutableData *data = [NSMutableData dataWithBytes:result length:strlen(result)];
        
        // Workaround: add missing </LHData>
        if (strstr(result, "<LHData") && !strstr(result, "</LHData")) {
            [data appendData:[@"</LHData>" dataUsingEncoding:NSUTF8StringEncoding]];
        }
        
        return data;
    }
}

@end
