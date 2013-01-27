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

#define NORMAL_HEIGHT               44
#define BIG_HEIGHT                  66
#define NORMAL_HEIGHT_CHAR_LIMIT    25

#define NUM_SECTIONS                2

#define SECT_APPEARANCE             0
#define SECT_PRAYER_PARTS           1

#define NUM_PRAYER_PARTS            6

static NSString *prayerPartTitles[] = {
    @"Evangéliumi kantikumok",
    @"Dicsőség az Atyának",
    @"Rubrikák",
    @"Miatyánk",
    @"Téged, Isten, dicsérünk... himnusz",
    @"A válaszos énekek teljes szövege",
    nil
};

static NSString *prayerPartOpts[] = {
    @"of1c", @"of1s", @"of1r", @"of1o", @"of1t", @"of1pr",
    nil
};

@interface BRSettingsViewController ()

@end

@implementation BRSettingsViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    // Fill set of long options
    NSMutableSet *opts = [NSMutableSet set];
    for (int i=0; prayerPartOpts[i]; i++) {
        if (prayerPartTitles[i].length > NORMAL_HEIGHT_CHAR_LIMIT) {
            [opts addObject:prayerPartOpts[i]];
        }
    }
    self.longOpts = opts;
    
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
    return NUM_SECTIONS;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    switch (section) {
        case SECT_APPEARANCE:
            return 1;
        case SECT_PRAYER_PARTS:
            return NUM_PRAYER_PARTS;
        default:
            return 0;
    }
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    switch (section) {
        case SECT_APPEARANCE:
            return @"Appearance";
        case SECT_PRAYER_PARTS:
            return @"Show prayer parts";
        default:
            return nil;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    switch (indexPath.section) {
        case SECT_PRAYER_PARTS:
        {
            NSString *optionId = prayerPartOpts[indexPath.row];
            return ([self.longOpts containsObject:optionId] ? BIG_HEIGHT : NORMAL_HEIGHT);
        }
        default:
            return NORMAL_HEIGHT;
    }
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
    else if (indexPath.section == SECT_PRAYER_PARTS) {
        NSString *optionId = prayerPartOpts[indexPath.row];
        NSString *cellIdentifier = ([self.longOpts containsObject:optionId] ? @"LongBoolCell" : @"BoolCell");
        BRBoolSettingsCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
        
        cell.optionId = optionId;
        cell.label.text = prayerPartTitles[indexPath.row];
        cell.switcher.on = [settings boolOption:prayerPartOpts[indexPath.row]];
        
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
