//
//  BRPrayerViewController.h
//  Breviar
//
//  Created by Gyimesi Akos on 9/7/12.
//
//

#import <UIKit/UIKit.h>
#import "BRWebViewController.h"
#import "BRPrayer.h"

@interface BRPrayerViewController : BRWebViewController

@property(strong) BRPrayer *prayer;
@property(weak) IBOutlet UIBarButtonItem *speakItem;
@property(weak) IBOutlet UIBarButtonItem *nightModeItem;
@property(weak) IBOutlet UIBarButtonItem *increaseFontItem;
@property(weak) IBOutlet UIBarButtonItem *decreaseFontItem;

- (IBAction)toggleSpeaker:(id)sender;
- (IBAction)toggleNightMode:(id)sender;
- (IBAction)increaseFontSize:(id)sender;
- (IBAction)decreaseFontSize:(id)sender;
@end
