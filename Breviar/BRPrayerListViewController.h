//
//  BRPrayerListViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import <UIKit/UIKit.h>
#import "BRDatePickerViewController.h"
#import "BRDay.h"

@interface BRPrayerListViewController : UITableViewController <BRDatePickerDelegate>

@property(strong) NSDate *date;
@property(strong) BRDay *day;
@property NSInteger celebrationIndex;

@end
