//
//  BRWebView.h
//  Breviar
//
//  Created by Akos Gyimesi on 23/02/14.
//
//

#import <UIKit/UIKit.h>

@interface BRWebView : UIWebView

@property(assign) BOOL scrollingInProgress;

- (BOOL)hadRecentScrolling;

@end
