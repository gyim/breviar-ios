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

@interface BRWebViewController : UIViewController <UIWebViewDelegate>
@property(strong) IBOutlet BRWebView *webView;
@property(strong) NSString *htmlContent;
@end
