//
//  BRFontPickerViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import <UIKit/UIKit.h>

@class BRFontPickerViewController;

@protocol BRFontPickerDelegate <NSObject>
- (void)fontPicker:(BRFontPickerViewController *)fontPicker didPickFont:(NSString *)fontFamily size:(NSInteger)fontSize;
@end

@interface BRFontPickerViewController : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate>

@property(strong) IBOutlet UIWebView *webView;
@property(strong) IBOutlet UIPickerView *pickerView;

@property(strong) NSString *fontFamily;
@property NSInteger fontSize;
@property(weak) NSObject<BRFontPickerDelegate> *delegate;

@end
