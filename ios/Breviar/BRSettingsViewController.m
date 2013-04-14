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
#import "BRUtil.h"

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
	return [BRSettings instance].sections.count;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
	NSDictionary *sectionObj = [[BRSettings instance].sections objectAtIndex:section];
	NSString *sectionId = [sectionObj objectForKey:@"id"];
	return BREVIAR_STR(sectionId);
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	NSDictionary *sectionObj = [[BRSettings instance].sections objectAtIndex:section];
	NSArray *sectionItems = [sectionObj objectForKey:@"items"];
	return sectionItems.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	NSDictionary *section = [[BRSettings instance].sections objectAtIndex:indexPath.section];
	NSArray *options = [section objectForKey:@"items"];
	NSDictionary *option = [options objectAtIndex:indexPath.row];
	NSString *optionType = [option objectForKey:@"type"];
	
	if ([optionType isEqualToString:@"bool"]) {
		// Boolean option
		NSArray *opts = [section objectForKey:@"items"];
		NSString *optId = [[opts objectAtIndex:indexPath.row] objectForKey:@"id"];
		NSString *optTitle = BREVIAR_STR(optId);
		
		UIFont *font = [UIFont systemFontOfSize:[UIFont labelFontSize]];
		CGSize size = [optTitle sizeWithFont:font constrainedToSize:CGSizeMake(CELL_LABEL_WIDTH, CGFLOAT_MAX)];
		return size.height + CELL_LABEL_MARGIN;
	}
	else {
		return CELL_NORMAL_HEIGHT;
	}
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
	BRSettings *settings = [BRSettings instance];
	NSDictionary *section = [settings.sections objectAtIndex:indexPath.section];
	NSArray *options = [section objectForKey:@"items"];
	NSDictionary *option = [options objectAtIndex:indexPath.row];
	NSString *optionType = [option objectForKey:@"type"];
	NSString *optionId = [option objectForKey:@"id"];
	
	if ([optionType isEqualToString:@"font"]) {
		BRFontSettingsCell *cell = [tableView dequeueReusableCellWithIdentifier:@"FontCell"];

		// Update font cell
		NSString *fontFamily = settings.prayerFontFamily;
		NSString *fontName = [[BRFontHelper instance] fontNameForFamily:fontFamily];
		NSInteger fontSize = settings.prayerFontSize;
		
		cell.optionId = optionId;
		cell.fontLabel.font = [UIFont fontWithName:fontFamily size:fontSize];
		cell.fontLabel.text = [NSString stringWithFormat:@"%@, %dpx", fontName, fontSize];
		
		return cell;
	}
	else if ([optionType isEqualToString:@"bool"]) {
		// Boolean option
		BRBoolSettingsCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BoolCell"];
		cell.optionId = optionId;
		cell.label.text = BREVIAR_STR(optionId);
		cell.switcher.on = [settings boolForOption:optionId];
		
		return cell;
	}
	
	return nil;
}

#pragma mark -
#pragma mark Transitions

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
	NSString *segueId = segue.identifier;
	NSIndexPath *indexPath = [self.tableView indexPathForSelectedRow];
	
	if ([segueId isEqualToString:@"ShowFontPicker"]) {
		BRFontSettingsCell *cell = (BRFontSettingsCell *)[self.tableView cellForRowAtIndexPath:indexPath];
		self.currentOptionId = cell.optionId;
		
		BRFontPickerViewController *fontPicker = segue.destinationViewController;
		fontPicker.fontFamily = [BRSettings instance].prayerFontFamily;
		fontPicker.fontSize = [BRSettings instance].prayerFontSize;
		fontPicker.delegate = self;
	}
}

- (void)fontPicker:(BRFontPickerViewController *)fontPicker didPickFont:(UIFont *)font
{
	[[BRSettings instance] setFont:font forOption:self.currentOptionId];
}

@end
