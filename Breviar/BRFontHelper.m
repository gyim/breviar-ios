//
//  BRFontHelper.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/9/12.
//
//

#import "BRFontHelper.h"

static BRFontHelper *_instance;

@implementation BRFontHelper

+ (BRFontHelper *)instance
{
    if (!_instance) {
        _instance = [[BRFontHelper alloc] init];
    }
    return _instance;
}

- (id)init {
    if (self = [super init]) {
        NSArray *fonts = @[
            @"HelveticaNeue",
            @"HelveticaNeue-Light",
            @"TimesNewRomanPSMT",
            @"Baskerville",
            @"Didot",
            @"GillSans",
            @"HoeflerText-Regular",
            @"Palatino-Roman",
            @"TrebuchetMS",
            @"Verdana"
        ];
        NSArray *names = @[
            @"Helvetica",
            @"Helvetica Light",
            @"Times",
            @"Baskerville",
            @"Didot",
            @"Gill Sans",
            @"Hoefler Text",
            @"Palatino",
            @"Trebuchet MS",
            @"Verdana"
        ];
        
        if (@available(iOS 9, *)) {
            fonts = [@[ @"-apple-system" ] arrayByAddingObjectsFromArray:fonts];
            names = [@[ @"San Francisco" ] arrayByAddingObjectsFromArray:names];
        }
        
        self.availableFonts = fonts;
        self.fontNames = [NSDictionary dictionaryWithObjects:names forKeys:fonts];
        
        if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
            self.availableSizes = @[ @(14), @(16), @(18), @(20), @(22), @(24), @(26), @(28), @(30), @(32), @(34) ];
        } else {
            self.availableSizes = @[ @(14), @(16), @(18), @(20), @(22), @(24), @(26), @(28), @(30) ];
        }
    }
    return self;
}

- (NSString *)fontNameForFamily:(NSString *)fontFamily
{
    return [self.fontNames objectForKey:fontFamily];
}

@end
