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
#import <sys/time.h>

@interface BRWebViewController ()

@property(strong) NSString *oldHtmlSource;
@property(strong) UITapGestureRecognizer *tapGesture;
@property(assign) struct timeval lastClickTime;
@property(strong) NSTimer *idleTimerReenableTimer;
@property(strong) NSTimer *showHideNavbarTimer;
@property(assign) BOOL fullScreenMode;

@end


@implementation BRWebViewController


#pragma mark - Lifetime & Navigation

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setupSharedWebView];
    self.navbarToggleEnabled = YES;
    self.fullScreenMode = NO;
}

- (void)setupSharedWebView
{
    // Use shared web view. Hide it now, and show it using animation once the content is loaded
    self.webView.alpha = 0;
    self.webView.navigationDelegate = self;
    self.webView.scrollView.decelerationRate = UIScrollViewDecelerationRateNormal;
    self.webView.configuration.dataDetectorTypes = WKDataDetectorTypeNone;

    [self.webView removeFromSuperview];
    [self.view insertSubview:self.webView atIndex:0];
    
    self.oldHtmlSource = @"";
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    self.webView.frame = self.view.bounds;
    self.webView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    [self setContentInsetsWithNavigationBarVisible:YES toolbarVisible:(self.toolbarItems.count > 0)];
    
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
        self.tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showHideNavBarAfterDelay:)];
        self.tapGesture.delegate = self;
        [self.view addGestureRecognizer:self.tapGesture];
    }
    
    // Disable automatic screen lock for 30 minutes. This should be enough for most prayers.
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    if (@available(iOS 10, *)) {
        self.idleTimerReenableTimer = [NSTimer scheduledTimerWithTimeInterval:1800 repeats:NO block:^(NSTimer *timer) {
            [UIApplication sharedApplication].idleTimerDisabled = NO;
        }];
    }
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:YES];
    
    [self.navigationController setToolbarHidden:YES animated:animated];
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
    [self.idleTimerReenableTimer invalidate];
    self.idleTimerReenableTimer = nil;
    
    // Cancel show/hide navbar timer
    [self.showHideNavbarTimer invalidate];
    self.showHideNavbarTimer = nil;
}

- (void)willMoveToParentViewController:(UIViewController *)parent
{
    [super willMoveToParentViewController:parent];
}

#pragma mark - Navigation Bar & Toolbar

- (void)showHideNavbar:(id)sender
{
    // On small scrolling events UIKit
    if (self.webView.scrollingInProgress || [self.webView hadRecentScrolling] || self.hadRecentLinkClick) {
        return;
    }
    
    self.fullScreenMode = !self.fullScreenMode;
    BOOL shouldShowToolBar = self.fullScreenMode && self.toolbarItems.count > 0;

    [UIView animateWithDuration:UINavigationControllerHideShowBarDuration
                     animations:^{
                         [self setNeedsStatusBarAppearanceUpdate];
                         [self.navigationController setNavigationBarHidden:self.fullScreenMode animated:YES];
                         [self.navigationController setToolbarHidden:shouldShowToolBar animated:YES];
                         
                         // If we're near the top (haven't scrolled too much) and we're about to show the nav bar, scroll down a bit so that the top content is not hidden by nav bar (without scrolling)
                         CGPoint scrollOffset = self.webView.scrollView.contentOffset;
                         if (!self.fullScreenMode && scrollOffset.y < self.view.safeAreaInsets.top) {
                             scrollOffset.y = -self.view.safeAreaInsets.top;
                             self.webView.scrollView.contentOffset = scrollOffset;
                         }
                         
                         [self setContentInsetsWithNavigationBarVisible:!self.fullScreenMode toolbarVisible:shouldShowToolBar];
                     }
                     completion:nil];
}

- (void)showHideNavBarAfterDelay:(id)sender
{
    self.showHideNavbarTimer = [NSTimer scheduledTimerWithTimeInterval:0.1 repeats:NO block:^(NSTimer * _Nonnull timer) {
        [self showHideNavbar:sender];
    }];
}

- (BOOL)prefersStatusBarHidden
{
    return self.fullScreenMode;
}

- (void)setContentInsetsWithNavigationBarVisible:(BOOL)navigationBarVisible toolbarVisible:(BOOL)toolbarVisible
{
    if (@available(iOS 11, *)) {
        // No need to adjust insets in iOS 11+
    }
    else {
        UIEdgeInsets contentInsets = UIEdgeInsetsMake(navigationBarVisible ? 64 : 0, 0, toolbarVisible ? 44 : 0, 0);
        self.webView.scrollView.contentInset = contentInsets;
        self.webView.scrollView.scrollIndicatorInsets = contentInsets;
    }
}

- (BOOL)hadRecentLinkClick
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec - self.lastClickTime.tv_sec)*1000 + (t.tv_usec-self.lastClickTime.tv_usec)/1000 < 500;
}

- (void)registerLinkClick
{
    struct timeval t;
    gettimeofday(&t, NULL);
    self.lastClickTime = t;
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    return YES;
}


#pragma mark - WKNavigationDelegate & Content Loading

- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    [UIView animateWithDuration:0.25 delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self.webView.alpha = 1;
    } completion:nil];
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    
    if ([navigationAction.request.URL.absoluteString rangeOfString:@"event://linkTouchStart"].location != NSNotFound) {
        struct timeval t;
        gettimeofday(&t, NULL);
        self.lastClickTime = t;
        decisionHandler(WKNavigationActionPolicyCancel);
    }
    else {
        // Allow requests to local files only
        if (navigationAction.request.URL.isFileURL) {
            decisionHandler(WKNavigationActionPolicyAllow);
        } else {
            decisionHandler(WKNavigationActionPolicyCancel);
        }
    }
}

- (void)updateWebViewContent
{
    BRSettings *settings = [BRSettings instance];
    
    NSMutableString *extraStylesheets = [[NSMutableString alloc] init];
    
    // Night mode
    NSString *colorScheme = [settings stringForOption:@"colorScheme"];
    int nightMode = 0;
    if ([colorScheme isEqualToString:@"dark"]) {
        nightMode = 1;
    } else if ([colorScheme isEqualToString:@"light"]) {
        nightMode = 0;
    } else {
        // Automatic dark/light mode
        if (@available(iOS 12.0, *)) {
            nightMode = (self.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark);
        }
    }

    if (nightMode) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-invert-colors.css'>"];
        self.webView.scrollView.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    } else {
        self.webView.scrollView.indicatorStyle = UIScrollViewIndicatorStyleDefault;
    }
    
    // Normal font instead of bold
    if ([settings boolForOption:@"of0fn"]) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-normal-font.css'>"];
    }
    
    // Blind-friendly
    if ([settings boolForOption:@"of0bf"]) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-blind-friendly.css'>"];
    }
    
    // Padding for iPad
    NSString *paddingTop = @"0px";
    NSString *paddingBottom = @"0px";
    NSString *paddingSides = UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad ? @"50px" : @"0px";
    NSString *padding = [NSString stringWithFormat:@"%@ %@ %@ %@",
                         paddingTop,
                         paddingSides,
                         paddingBottom,
                         paddingSides];
    
    NSString *htmlSource =
    [NSString stringWithFormat:
     @"<!DOCTYPE html>\n"
     "<html><head>\n"
     "  <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>\n"
     "  <link rel='stylesheet' type='text/css' href='html/breviar.css'>\n"
     "  <script type='text/javascript' src='breviar-ios.js'></script>\n"
     "  <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
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
    
    // Call the delegate method even if we don't reload the content
    else {
        if ([self.webView.navigationDelegate respondsToSelector:@selector(webView:didFinishNavigation:)]) {
            [self.webView.navigationDelegate webView:self.webView didFinishNavigation:nil];
        }
    }
}

@end
