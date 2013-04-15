//
//  BRStringOptionPickerViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 4/14/13.
//
//

#import <UIKit/UIKit.h>

@class BRStringOptionPickerViewController;

@protocol BRStringOptionPickerDelegate <NSObject>
- (void)stringOptionPicker:(BRStringOptionPickerViewController *)picker didPickOption:(NSString *)value;
@end

@interface BRStringOptionPickerViewController : UITableViewController

@property(weak) NSObject<BRStringOptionPickerDelegate> *delegate;
@property(strong) NSArray *options;
@property(strong) NSString *currentValue;

@end
