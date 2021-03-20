//
//  BRFontPickerViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "BRViewController.h"

@class BRFontPickerViewController;

@protocol BRFontPickerDelegate <NSObject>
- (void)fontPicker:(BRFontPickerViewController *)fontPicker didPickFontFamily:(NSString *)familyName size:(NSInteger)size;
@end

@interface BRFontPickerViewController : BRViewController <UIPickerViewDataSource, UIPickerViewDelegate>

@property(strong) NSString *fontFamily;
@property NSInteger fontSize;
@property(weak) NSObject<BRFontPickerDelegate> *delegate;

@end
