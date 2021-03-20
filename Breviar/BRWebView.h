//
//  BRWebView.h
//  Breviar
//
//  Created by Akos Gyimesi on 23/02/14.
//
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface BRWebView : WKWebView <UIScrollViewDelegate>

@property(assign) BOOL scrollingInProgress;

- (BOOL)hadRecentScrolling;

@end
