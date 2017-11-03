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
#import "GAI.h"
#import "GAIFields.h"
#import "GAIDictionaryBuilder.h"

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
                               @"hu": @"html/include_hu"};
    
    NSString *filename = [[NSBundle mainBundle] pathForResource:@"about" ofType:@"htm" inDirectory:[langDirs objectForKey:lang]];
    NSString *html = [NSString stringWithContentsOfFile:filename encoding:NSUTF8StringEncoding error:nil];
    
    // We want to insert full links including protocol, so we first need to remove unnecessary protocols from the templated HTML files
    html = [html stringByReplacingOccurrencesOfString:@"href=\"http://" withString:@"href=\""];
    
    // Replace all placeholders like [KEY] with proper values
    NSString *version = [NSString stringWithFormat:@"%@ (%@)", [NSBundle mainBundle].infoDictionary[@"CFBundleShortVersionString"], BUILD_NUMBER];
    NSString *appName = [NSString stringWithFormat:@"%@ (iOS)", [NSBundle mainBundle].infoDictionary[@"CFBundleDisplayName"]];
    NSDictionary *sites = @{
        @"sk": @"http://breviar.sk",
        @"cz": @"http://breviar.cz",
        @"hu": @"http://breviar.sk/hu",
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
    
    // Track page
    id<GAITracker> tracker = [[GAI sharedInstance] defaultTracker];
    [tracker set:kGAIScreenName value:@"About"];
    [tracker send:[[GAIDictionaryBuilder createScreenView] build]];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if (navigationType == UIWebViewNavigationTypeLinkClicked) {
        [[UIApplication sharedApplication] openURL:request.URL];
        return NO;
    } else {
        return [super webView:webView shouldStartLoadWithRequest:request navigationType:navigationType];
    }
}

@end
