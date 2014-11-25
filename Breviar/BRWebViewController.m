//
//  BRWebViewController.m
//  Breviar
//
//  Created by Akos Gyimesi on 13/01/14.
//
//

#import "BRWebViewController.h"
#import "BRSettings.h"
#import "BRCGIQuery.h"
#import "BRUtil.h"

@interface BRWebViewController ()
@property(strong) NSString *oldHtmlSource;
@property(strong) UITapGestureRecognizer *tapGesture;
@property(assign) struct timeval lastClickTime;
@end

@implementation BRWebViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setupSharedWebView];
    self.navbarToggleEnabled = YES;
}

- (void) setupSharedWebView
{
    // Use shared web view. Hide it now, and show it using animation once the content is loaded
    self.webView.alpha = 0;
    self.webView.delegate = self;
    self.webView.scrollView.decelerationRate = UIScrollViewDecelerationRateNormal;
    
    [self.webView removeFromSuperview];
    [self.view addSubview:self.webView];
    
    self.oldHtmlSource = @"";
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // If we are coming from a subpage, move its shared webview here
    if (self.subpageController) {
        self.webView = self.subpageController.webView;
        [self setupSharedWebView];
    }
    
    self.webView.frame = self.view.bounds;
    self.webView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    struct timeval t;
    gettimeofday(&t, NULL);
    self.lastClickTime = t;
    
    [self updateWebViewContent];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if (self.navbarToggleEnabled) {
        // Add gesture recognizer
        self.tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showHideNavbar:)];
        self.tapGesture.delegate = self;
        [self.view addGestureRecognizer:self.tapGesture];
    }
    
    // Disable automatic screen lock
    [UIApplication sharedApplication].idleTimerDisabled = YES;
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    // Remove gesture recognizer
    if (self.tapGesture) {
        [self.view removeGestureRecognizer:self.tapGesture];
        self.tapGesture = nil;
    }
    
    // Re-enable automatic screen lock
    [UIApplication sharedApplication].idleTimerDisabled = NO;
}

- (void)showHideNavbar:(id)sender
{
    // On small scrolling events UIKit
    if (self.webView.scrollingInProgress || [self.webView hadRecentScrolling] || self.hadRecentLinkClick) {
        return;
    }
    
    BOOL navbarHidden = [UIApplication sharedApplication].isStatusBarHidden;
    
    if (navbarHidden) {
        self.navigationController.navigationBarHidden = NO;
        self.navigationController.navigationBar.alpha = 0;
    }
    
    [UIView animateWithDuration:UINavigationControllerHideShowBarDuration
                     animations:^{
                         [[UIApplication sharedApplication] setStatusBarHidden:!navbarHidden withAnimation:UIStatusBarAnimationFade];
                         self.navigationController.navigationBar.alpha = navbarHidden ? 1.0 : 0.0;
                     }
                     completion:^(BOOL finished) {
                         if (finished && !navbarHidden) {
                             self.navigationController.navigationBarHidden = YES;
                         }
                     }
     ];
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    return YES;
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    [UIView animateWithDuration:0.25 delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self.webView.alpha = 1;
    } completion:nil];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"ShowSubpage"]) {
        NSURL *url = sender;
        
        // Parse URL
        NSArray *argList = [url.query componentsSeparatedByString:@"&"];
        NSMutableDictionary *args = [[NSMutableDictionary alloc] init];
        for (NSString *kv in argList) {
            NSArray *kvParts = [kv componentsSeparatedByString:@"="];
            NSString *k = [kvParts objectAtIndex:0];
            NSString *v = [kvParts objectAtIndex:1];
            [args setObject:v forKey:k];
        }
        
        // Run query and show result
        NSString *body = [BRCGIQuery queryWithArgs:args];
        self.subpageController = segue.destinationViewController;
        self.subpageController.webView = self.webView;
        self.subpageController.htmlContent = [NSString stringWithFormat:@"<div id=\"prayer-custom\">%@</div>", body];
        
        // Set subpage title
        NSString *subpageTitleKey = [args objectForKey:@"st"];
        self.subpageController.title = subpageTitleKey ? BREVIAR_STR(subpageTitleKey) : self.navigationController.title;
        
        [UIApplication sharedApplication].statusBarHidden = NO;
        self.navigationController.navigationBarHidden = NO;
        self.navigationController.navigationBar.alpha = 1.0;
    }
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if ([request.URL.absoluteString containsString:@".cgi?"]) {
        [self performSegueWithIdentifier:@"ShowSubpage" sender:request.URL];
        return NO;
    } else if ([request.URL.absoluteString containsString:@"event://linkTouchStart"]) {
        struct timeval t;
        gettimeofday(&t, NULL);
        self.lastClickTime = t;
        return NO;
    }
    else {
        // Allow requests to local files only
        return request.URL.isFileURL;
    }
}

- (BOOL)hadRecentLinkClick
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec - self.lastClickTime.tv_sec)*1000 + (t.tv_usec-self.lastClickTime.tv_usec)/1000 < 500;
}

- (void)updateWebViewContent
{
    BRSettings *settings = [BRSettings instance];
    
    NSMutableString *extraStylesheets = [[NSMutableString alloc] init];
    if ([settings boolForOption:@"of0fn"]) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-normal-font.css'>"];
    }
    
    // Night mode
    if ([settings boolForOption:@"of2nr"]) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-invert-colors.css'>"];
        self.view.backgroundColor = [UIColor colorWithHex:0x333333];
        self.webView.scrollView.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    } else {
        self.view.backgroundColor = [UIColor colorWithHex:0xFBFCD7];
        self.webView.scrollView.indicatorStyle = UIScrollViewIndicatorStyleDefault;
    }
    
    // Padding for iPad
    NSString *padding;
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        padding = @"64px 50px 0px 50px";
    } else {
        padding = @"64px 0px 0px 0px";
    }
    
    NSString *htmlSource =
    [NSString stringWithFormat:
     @"<!DOCTYPE html>\n"
     "<html><head>\n"
     "  <meta http-equiv='Content-Type' content='text/html; charset=windows-1250'>\n"
     "  <link rel='stylesheet' type='text/css' href='html/breviar.css'>\n"
     "  <link rel='stylesheet' type='text/css' href='breviar-ios.css'>\n"
     "  <script type='text/javascript' src='breviar-ios.js'></script>\n"
     "  %@\n"
     "</head>\n"
     "<body style='padding: %@; font: %ldpx %@;'>%@\n"
     "<script type='text/javascript'>pageReady()</script>\n"
     "</body>\n"
     "</html>",
     extraStylesheets,
     padding,
     (long)settings.prayerFontSize,
     settings.prayerFontFamily,
     self.htmlContent];
    
    if (![htmlSource isEqual:self.oldHtmlSource]) {
        NSURL *baseURL = [NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
        [self.webView loadHTMLString:htmlSource baseURL:baseURL];
        self.oldHtmlSource = htmlSource;
    }
}

@end
