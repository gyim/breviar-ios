//
//  BRWebView.h
//  Breviar
//
//  Created by Akos Gyimesi on 23/02/14.
//
//

#import <UIKit/UIKit.h>
#import <sys/time.h>

@interface BRWebView : UIWebView {
    struct timeval lastScrollingTime;
}

@property(assign) BOOL scrollingInProgress;

- (BOOL)hadRecentScrolling;

@end
