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


#pragma mark - Lifetime & Navigation

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setupSharedWebView];
    self.navbarToggleEnabled = YES;
}

- (void)setupSharedWebView
{
    // Use shared web view. Hide it now, and show it using animation once the content is loaded
    self.webView.alpha = 0;
    self.webView.delegate = self;
    self.webView.scrollView.decelerationRate = UIScrollViewDecelerationRateNormal;
    self.webView.dataDetectorTypes = UIDataDetectorTypeNone;

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
        self.tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(showHideNavbar:)];
        self.tapGesture.delegate = self;
        [self.view addGestureRecognizer:self.tapGesture];
    }
    
    // Disable automatic screen lock
    [UIApplication sharedApplication].idleTimerDisabled = YES;
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
}

#pragma mark - Navigation Bar & Toolbar

- (void)showHideNavbar:(id)sender
{
    // On small scrolling events UIKit
    if (self.webView.scrollingInProgress || [self.webView hadRecentScrolling] || self.hadRecentLinkClick) {
        return;
    }
    
    BOOL navbarHidden = [UIApplication sharedApplication].isStatusBarHidden;
    BOOL shouldShowNavigationBar = navbarHidden;
    BOOL shouldShowToolBar = navbarHidden && self.toolbarItems.count > 0;

    [UIView animateWithDuration:UINavigationControllerHideShowBarDuration
                     animations:^{
                         [[UIApplication sharedApplication] setStatusBarHidden:!shouldShowNavigationBar withAnimation:UIStatusBarAnimationSlide];
                         [self.navigationController setNavigationBarHidden:!shouldShowNavigationBar animated:YES];
                         [self.navigationController setToolbarHidden:!shouldShowToolBar animated:YES];
                         
                         // If we're near the top (haven't scrolled too much) and we're about to show the nav bar, scroll down a bit so that the top content is not hidden by nav bar (without scrolling)
                         CGPoint scrollOffset = self.webView.scrollView.contentOffset;
                         if (shouldShowNavigationBar && scrollOffset.y < 30) {
                             scrollOffset.y = -64;
                             self.webView.scrollView.contentOffset = scrollOffset;
                         }
                         
                         [self setContentInsetsWithNavigationBarVisible:shouldShowNavigationBar toolbarVisible:shouldShowToolBar];
                     }
                     completion:nil];
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

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    return YES;
}


#pragma mark - UIWebViewDelegate & Content Loading

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    [UIView animateWithDuration:0.25 delay:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self.webView.alpha = 1;
    } completion:nil];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if ([request.URL.absoluteString rangeOfString:@"event://linkTouchStart"].location != NSNotFound) {
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

- (void)updateWebViewContent
{
    BRSettings *settings = [BRSettings instance];
    
    NSMutableString *extraStylesheets = [[NSMutableString alloc] init];
    
    // Night mode
    if ([settings boolForOption:@"of2nr"]) {
        [extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-invert-colors.css'>"];
        self.view.backgroundColor = [UIColor colorWithHex:0x191919];
        self.webView.scrollView.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    } else {
        self.view.backgroundColor = [UIColor colorWithHex:0xFBFCD7];
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
    
    // Background override (beamer/AMOLED)
    if ([settings boolForOption:@"of2bo"]) {
		if ([settings boolForOption:@"of2nr"]) {
			[extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-background-ov-invert.css'>"];
            self.view.backgroundColor = [UIColor blackColor];
		} else {
			[extraStylesheets appendString:@"<link rel='stylesheet' type='text/css' href='html/breviar-background-override.css'>"];
            self.view.backgroundColor = [UIColor whiteColor];
		}
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
    
    // Call the delegate method even if we don't reload the content
    else {
        if ([self.webView.delegate respondsToSelector:@selector(webViewDidFinishLoad:)]) {
            [self.webView.delegate webViewDidFinishLoad:self.webView];
        }
    }
}

@end
