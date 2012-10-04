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
		self.availableFonts = [NSArray arrayWithObjects:
							   @"Baskerville",
							   @"TimesNewRomanPSMT",
							   @"HelveticaNeue",
							   @"HelveticaNeue-Light",
							   @"Verdana",
							   nil];
		
		self.fontNames = [NSDictionary dictionaryWithObjectsAndKeys:
						  @"Baskerville",      @"Baskerville",
						  @"Times",            @"TimesNewRomanPSMT",
						  @"Helvetica",        @"HelveticaNeue",
						  @"Helvetica Light",  @"HelveticaNeue-Light",
						  @"Verdana",          @"Verdana",
						  nil];
		
		self.availableSizes = [NSArray arrayWithObjects:
							   [NSNumber numberWithInt:14],
							   [NSNumber numberWithInt:16],
							   [NSNumber numberWithInt:18],
							   [NSNumber numberWithInt:20],
							   [NSNumber numberWithInt:22],
							   nil];
	}
	return self;
}

- (NSString *)fontNameForFamily:(NSString *)fontFamily
{
	return [self.fontNames objectForKey:fontFamily];
}

@end
