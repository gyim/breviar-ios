//
//  BRPrayerListViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import <UIKit/UIKit.h>
#import "BRDatePickerViewController.h"

@interface BRPrayerListViewController : UITableViewController <BRDatePickerDelegate>
@property(strong) NSDate *date;
@property(strong) IBOutlet UILabel *dateLabel;
@end
