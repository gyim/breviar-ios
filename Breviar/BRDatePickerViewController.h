//
//  BRDatePickerViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import <UIKit/UIKit.h>

@class BRDatePickerViewController;

@protocol BRDatePickerDelegate <NSObject>
- (void)datePicker:(BRDatePickerViewController *)datePicker pickedDate:(NSDate *)date;
@end

@interface BRDatePickerViewController : UIViewController

@property (weak, nonatomic) IBOutlet NSObject<BRDatePickerDelegate> *datePickerDelegate;
@property (strong, nonatomic) NSDate *initialDate;

@end
