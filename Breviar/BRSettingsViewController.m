//
//  BRSettingsViewController.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import "BRSettingsViewController.h"
#import "BRFontHelper.h"
#import "BRSettings.h"

@interface BRSettingsViewController ()

@end

@implementation BRSettingsViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	
	BRSettings *settings = [BRSettings instance];
	
	// Update font cell
	NSString *fontFamily = settings.prayerFontFamily;
	NSString *fontName = [[BRFontHelper instance] fontNameForFamily:fontFamily];
	NSInteger fontSize = settings.prayerFontSize;
	
	self.prayerFontLabel.font = [UIFont fontWithName:fontFamily size:fontSize];
	self.prayerFontLabel.text = [NSString stringWithFormat:@"%@, %dpx", fontName, fontSize];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
	NSString *segueId = segue.identifier;
	
	if ([segueId isEqualToString:@"ShowFontPicker"]) {
		BRFontPickerViewController *fontPicker = segue.destinationViewController;
		fontPicker.fontFamily = [BRSettings instance].prayerFontFamily;
		fontPicker.fontSize = [BRSettings instance].prayerFontSize;
		fontPicker.delegate = self;
	}
}

- (void)fontPicker:(BRFontPickerViewController *)fontPicker didPickFont:(NSString *)fontFamily size:(NSInteger)fontSize
{
	[BRSettings instance].prayerFontFamily = fontFamily;
	[BRSettings instance].prayerFontSize = fontSize;
}

@end
