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

@interface BRWebViewController : UIViewController <WKNavigationDelegate,UIGestureRecognizerDelegate>

@property(strong) IBOutlet BRWebView *webView;
@property(strong) NSString *htmlContent;
@property BOOL navbarToggleEnabled;

- (void)updateWebViewContent;
- (void)setupSharedWebView;

@end
