//
//  BRSettingsViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import <UIKit/UIKit.h>
#import "BRFontPickerViewController.h"

@interface BRSettingsViewController : UITableViewController <BRFontPickerDelegate, UITableViewDelegate, UITableViewDataSource>

@property(strong) NSSet *longOpts;
@end
