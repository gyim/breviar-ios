//
//  BRPrayerListViewController.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayerListViewController.h"
#import "BRPrayerViewController.h"
#import "BRDataSource.h"

static NSString *prayerSegues[] = {
    [BRInvitatory]         = @"ShowInvitatory",
    [BROfficeOfReadings]   = @"ShowOfficeOfReadings",
    [BRMorningPrayer]      = @"ShowMorningPrayer",
    [BRMidMorningPrayer]   = @"ShowMidMorningPrayer",
    [BRMiddayPrayer]       = @"ShowMiddayPrayer",
    [BRMidAfternoonPrayer] = @"ShowMidAfternoonPrayer",
    [BREveningPrayer]      = @"ShowEveningPrayer",
    [BRCompline]           = @"ShowCompline",
    nil
};

@interface BRPrayerListViewController ()

@end

@implementation BRPrayerListViewController

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
    [self loadDataForDate:[NSDate date]];
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

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 3;
}

#pragma mark -
#pragma mark UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    switch (section) {
        case 0:
            return self.day.celebrations.count + 1;
        case 1:
            return 8;
        case 2:
            return 1;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0) {
        if (indexPath.row == 0) {
            // Date cell
            UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DateCell"];

            NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
            formatter.dateStyle = NSDateFormatterLongStyle;
            formatter.timeStyle = NSDateFormatterNoStyle;
            
            cell.textLabel.text = [formatter stringFromDate:self.date];
            return cell;
        }
        else {
            // Celebration cell
            UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CelebrationCell"];
            
            BRCelebration *celebration = [self.day.celebrations objectAtIndex:indexPath.row-1];
            cell.textLabel.text = celebration.title;
            cell.detailTextLabel.text = celebration.subtitle;
            cell.accessoryType = (self.celebrationIndex == indexPath.row-1 ? UITableViewCellAccessoryCheckmark : UITableViewCellAccessoryNone);
            
            return cell;
        }
    }
    else if (indexPath.section == 1) {
        // Prayer cell
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"PrayerCell"];
        
        BRCelebration *celebration = [self.day.celebrations objectAtIndex:self.celebrationIndex];
        BRPrayer *prayer = [celebration.prayers objectAtIndex:indexPath.row];
        cell.textLabel.text = prayer.title;
        
        return cell;
    }
    else if (indexPath.section == 2) {
        // Settings cell
        return [tableView dequeueReusableCellWithIdentifier:@"SettingsCell"];
    }
    return nil;
}

#pragma mark -
#pragma mark UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0 && indexPath.row > 0) {
        // Select celebration
        NSIndexPath *oldIndexPath = [NSIndexPath indexPathForRow:self.celebrationIndex+1 inSection:indexPath.section];
        [self.tableView cellForRowAtIndexPath:oldIndexPath].accessoryType = UITableViewCellAccessoryNone;
        [self.tableView cellForRowAtIndexPath:indexPath].accessoryType = UITableViewCellAccessoryCheckmark;
        
        self.celebrationIndex = indexPath.row-1;
        [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
    }
}

#pragma mark -
#pragma mark UI transitions

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    NSString *segueId = segue.identifier;
    
    if ([segueId isEqualToString:@"ShowPrayer"]) {
        BRPrayerViewController *destController = segue.destinationViewController;
        NSIndexPath *indexPath = [self.tableView indexPathForSelectedRow];
        BRCelebration *celebration = [self.day.celebrations objectAtIndex:self.celebrationIndex];
        destController.prayer = [celebration.prayers objectAtIndex:indexPath.row];
    }
    else if ([segueId isEqualToString:@"ShowDatePicker"]) {
        BRDatePickerViewController *destController = segue.destinationViewController;
        destController.initialDate = self.date;
        destController.datePickerDelegate = self;
    }
}

- (void)datePicker:(BRDatePickerViewController *)datePicker pickedDate:(NSDate *)date
{
    [self loadDataForDate:date];
    [self dismissModalViewControllerAnimated:YES];
}

#pragma mark -
#pragma mark Data handling

- (void)loadDataForDate:(NSDate *)date
{
    self.date = date;
    self.day = [[BRDataSource instance] dayForDate:date];
    self.celebrationIndex = 0;
}

@end
