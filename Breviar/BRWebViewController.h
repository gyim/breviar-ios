//
//  BRWebViewController.h
//  Breviar
//
//  Created by Akos Gyimesi on 13/01/14.
//
//

#import <UIKit/UIKit.h>
#import "BRViewController.h"
#import "BRWebView.h"

@interface BRWebViewController : UIViewController <UIWebViewDelegate,UIGestureRecognizerDelegate>
@property(strong) IBOutlet BRWebView *webView;
@property(strong) NSString *htmlContent;
@property(strong) BRWebViewController *subpageController;
@property BOOL navbarToggleEnabled;

- (void)setupSharedWebView;
- (void)updateWebViewContent;
@end
