//
//  BRPrayerListViewController.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import "BRPrayerListViewController.h"
#import "BRPrayerViewController.h"
#import "BRDay.h"

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
	self.date = [NSDate date];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	
	NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
	formatter.dateStyle = NSDateFormatterLongStyle;
	formatter.timeStyle = NSDateFormatterNoStyle;
	
	self.dateLabel.text = [formatter stringFromDate:self.date];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{	
	NSString *segueId = segue.identifier;
	
	// Prayer segues
	int i;
	for (i=0; prayerSegues[i]; i++) {
		if ([segueId isEqualToString:prayerSegues[i]]) {
			BRPrayerViewController *destController = segue.destinationViewController;
			
			// Get celebration ID
			BRDay *day = [BRDay dayWithDate:self.date];
			NSInteger celebrationId = 0;
			BRCelebration *celebration = [day.celebrations objectAtIndex:0];
			if (celebration) {
				celebrationId = celebration.celebrationId;
			}
			
			// Get prayer data
			BRPrayerType prayerType = (BRPrayerType)i;
			destController.prayer = [BRPrayer prayerWithType:prayerType celebration:0 date:self.date];
			return;
		}
	}
	
	// Other segues
	if ([segueId isEqualToString:@"ShowDatePicker"]) {
		BRDatePickerViewController *destController = segue.destinationViewController;
		destController.initialDate = self.date;
		destController.datePickerDelegate = self;
	}
}

- (void)datePicker:(BRDatePickerViewController *)datePicker pickedDate:(NSDate *)date
{
	self.date = date;
	[self dismissModalViewControllerAnimated:YES];
}

@end
