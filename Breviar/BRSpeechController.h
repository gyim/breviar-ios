//
//  BRSpeechController.h
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 22..
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "BRPrayer.h"

typedef enum {
    BRSpeechDisabled = 0,
    BRSpeechStarting = 1,
    BRSpeechPlaying = 2,
    BRSpeechPaused = 3,
} BRSpeechState;

@protocol BRSpeechControllerDelegate
- (void)speechStateChanged:(BRSpeechState)speechState;
@end

@interface BRSpeechController : NSObject <WKNavigationDelegate>

@property(weak) id<BRSpeechControllerDelegate> delegate;
@property(assign) BRSpeechState speechState;
@property(strong) WKWebView *webView;

- (void)beginSession:(BRPrayer *)prayer;
- (void)endSession;
- (void)startPlayback;
- (void)pausePlayback;
- (void)resetText;
- (void)togglePlayback;

@end
