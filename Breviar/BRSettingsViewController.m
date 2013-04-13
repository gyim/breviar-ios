//
//  BRSettingsViewController.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import "BRSettingsViewController.h"
#import "BRFontHelper.h"
#import "BRFontSettingsCell.h"
#import "BRBoolSettingsCell.h"
#import "BRSettings.h"

#define CELL_NORMAL_HEIGHT			44
#define CELL_LABEL_WIDTH			192
#define CELL_LABEL_MARGIN			24

#define SECT_APPEARANCE				0
#define SECT_PRAYER_PARTS			1
#define SECT_PRAYER_TEXT			2
#define SECT_OTHER					3

@interface BRSettingsViewController ()

@end

@implementation BRSettingsViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

	self.sections = @[@"appearance", @"common_parts", @"prayer_text", @"calendar", @"other"];
	self.optsForSections = @{
		@"common_parts": @[@"of1c", @"of1s", @"of1r", @"of1o", @"of1t", @"of1pr"],
		@"prayer_text": @[@"of0v", @"of0cit"],
		@"calendar": @[@"of0zjvne", @"of0nanne", @"of0tkne"],
		@"other": @[@"of1zspc", @"of1spspc", @"of1sp", @"of1dps", @"of1z95", @"of1prz", @"of1vkp", @"of1v", @"of2a"],
	};
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	[self.tableView reloadData];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark -
#pragma mark Settings table

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
	return self.sections.count;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
	NSString *sectionId = [self.sections objectAtIndex:section];
	return [[NSBundle mainBundle] localizedStringForKey:sectionId value:@"" table:@"Settings"];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	NSString *sectionId = [self.sections objectAtIndex:section];
	if ([sectionId isEqualToString:@"appearance"]) {
		return 1;
	}
	else {
		return [[self.optsForSections objectForKey:sectionId] count];
	}
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	NSString *sectionId = [self.sections objectAtIndex:indexPath.section];
	
	if ([sectionId isEqualToString:@"appearance"]) {
		return CELL_NORMAL_HEIGHT;
	}
	else {
		NSArray *opts = [self.optsForSections objectForKey:sectionId];
		NSString *optId = [opts objectAtIndex:indexPath.row];
		NSString *optTitle = [[NSBundle mainBundle] localizedStringForKey:optId value:@"" table:@"Settings"];
		
		UIFont *font = [UIFont systemFontOfSize:[UIFont labelFontSize]];
		CGSize size = [optTitle sizeWithFont:font constrainedToSize:CGSizeMake(CELL_LABEL_WIDTH, CGFLOAT_MAX)];
		return size.height + CELL_LABEL_MARGIN;
	}
	
	return CELL_NORMAL_HEIGHT;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	BRSettings *settings = [BRSettings instance];
	
	if (indexPath.section == SECT_APPEARANCE && indexPath.row == 0) {
		BRFontSettingsCell *cell = [tableView dequeueReusableCellWithIdentifier:@"FontCell"];

		// Update font cell
		NSString *fontFamily = settings.prayerFontFamily;
		NSString *fontName = [[BRFontHelper instance] fontNameForFamily:fontFamily];
		NSInteger fontSize = settings.prayerFontSize;
		
		cell.fontLabel.font = [UIFont fontWithName:fontFamily size:fontSize];
		cell.fontLabel.text = [NSString stringWithFormat:@"%@, %dpx", fontName, fontSize];
		
		return cell;
	}
	else {
		// Boolean option
		NSString *sectionId = [self.sections objectAtIndex:indexPath.section];
		NSArray *opts = [self.optsForSections objectForKey:sectionId];
		NSString *optId = [opts objectAtIndex:indexPath.row];
		NSString *optTitle = [[NSBundle mainBundle] localizedStringForKey:optId value:@"" table:@"Settings"];

		BRBoolSettingsCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BoolCell"];
		cell.optionId = optId;
		cell.label.text = optTitle;
		cell.switcher.on = [settings boolOption:optId];
		
		return cell;
	}
	
	return nil;
}

#pragma mark -
#pragma mark Transitions

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
