//
//  BRAboutViewController.m
//  Breviar
//
//  Created by Akos Gyimesi on 13/01/14.
//
//

#import "BRAboutViewController.h"
#import "BRSettings.h"
#import "config.build.h"

@interface BRAboutViewController ()

@end

@implementation BRAboutViewController

- (void)viewWillAppear:(BOOL)animated
{
    self.navbarToggleEnabled = NO;
    
    // Determine about.htm location
    BRSettings *settings = [BRSettings instance];
    
    NSString *lang = [settings stringForOption:@"j"];
    NSDictionary *langDirs = @{@"sk": @"html/include",
                               @"cz": @"html/include_cz",
                               @"c2": @"html/include_czop",
                               @"hu": @"html/include_hu"};
    
    NSString *filename = [[NSBundle mainBundle] pathForResource:@"about" ofType:@"htm" inDirectory:[langDirs objectForKey:lang]];
    NSString *html = [NSString stringWithContentsOfFile:filename encoding:NSUTF8StringEncoding error:nil];
    
    // We want to insert full links including protocol, so we first need to remove unnecessary protocols from the templated HTML files
    html = [html stringByReplacingOccurrencesOfString:@"href=\"http://" withString:@"href=\""];
    
    // Replace all placeholders like [KEY] with proper values
    NSString *version = [NSString stringWithFormat:@"%@ (%@)", [NSBundle mainBundle].infoDictionary[@"CFBundleShortVersionString"], BUILD_NUMBER];
    NSString *appName = [NSString stringWithFormat:@"%@ (iOS)", [NSBundle mainBundle].infoDictionary[@"CFBundleDisplayName"]];
    NSDictionary *sites = @{
        @"sk": @"https://breviar.sk",
        @"cz": @"http://breviar.cz",
        @"c2": @"https://breviar.sk/czop",
        @"hu": @"https://breviar.sk/hu",
    };

    NSDictionary *replacements = @{
        @"VERSION": version,
        @"PROJECT-URL": sites[lang],
        @"E-MAIL": @"apple@breviar.sk",
        @"APP-NAME": appName,
        @"PROJECT-SOURCE-STORAGE": @"GitHub",
        @"PROJECT-SOURCE-URL": @"https://github.com/gyim/breviar-ios",
        @"SPECIAL-CREDITS": @"",
        @"PLATFORM-ANDROID": @"",
        @"PLATFORM-IOS": @"iOS App",
    };
    for (NSString *key in replacements) {
        NSString *placeholder = [NSString stringWithFormat:@"[%@]", key];
        NSString *value = replacements[key];
        html = [html stringByReplacingOccurrencesOfString:placeholder withString:value];
    }
    
    // Show content
    self.htmlContent = [NSString stringWithFormat:@"<div id='about'>%@</div>", html];
    [super viewWillAppear:animated];
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    if (navigationAction.navigationType == WKNavigationTypeLinkActivated) {
        [[UIApplication sharedApplication] openURL:navigationAction.request.URL options:@{} completionHandler:nil];
        decisionHandler(WKNavigationActionPolicyCancel);
    } else {
        [super webView:webView decidePolicyForNavigationAction:navigationAction decisionHandler:decisionHandler];
    }
}

@end
