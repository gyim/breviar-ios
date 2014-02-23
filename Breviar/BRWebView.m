//
//  BRWebView.m
//  Breviar
//
//  Created by Akos Gyimesi on 23/02/14.
//
//

#import "BRWebView.h"

@implementation BRWebView

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    [super scrollViewWillBeginDragging:scrollView];
    self.scrollingInProgress = YES;
}

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
    [super scrollViewDidEndDragging:scrollView willDecelerate:decelerate];
    self.scrollingInProgress = NO;
    gettimeofday(&lastScrollingTime, NULL);
}

- (BOOL)hadRecentScrolling
{
    struct timeval ts;
    gettimeofday(&ts, NULL);
    
    if (!lastScrollingTime.tv_sec) {
        return NO;
    }
    
    unsigned long long elapsedMsecs = (ts.tv_sec-lastScrollingTime.tv_sec)*1000LL + (ts.tv_usec-lastScrollingTime.tv_usec)/1000LL;
    return elapsedMsecs < 100;
}

@end
