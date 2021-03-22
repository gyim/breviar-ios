//
//  BRSpeechController.m
//  Breviar
//
//  Created by Akos Gyimesi on 2021. 03. 22..
//

#import "BRSpeechController.h"
#import "BRSettings.h"

#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>

@interface BRSpeechController ()
@property (strong, nonatomic) BRPrayer *prayer;
@property (strong, nonatomic) NSString *prayerText;
@property (strong, nonatomic) AVSpeechSynthesizer *speechSynthesizer;
@end

@implementation BRSpeechController

- (id)init {
    if (self = [super init]) {
        self.webView = [[WKWebView alloc] init];
        self.webView.navigationDelegate = self;
        self.speechState = BRSpeechDisabled;
    }
    return self;
}

- (void)beginSession:(BRPrayer *)prayer {
    // Store prayer
    self.prayer = prayer;
    
    // Start audio session
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setActive:YES error:nil];
    [session setCategory:AVAudioSessionCategoryPlayback error:nil];
    [[UIApplication sharedApplication] beginReceivingRemoteControlEvents];

    MPRemoteCommandCenter *commandCenter = [MPRemoteCommandCenter sharedCommandCenter];
    [commandCenter.playCommand addTargetWithHandler:^MPRemoteCommandHandlerStatus(MPRemoteCommandEvent * _Nonnull event) {
        [self startPlayback];
        return MPRemoteCommandHandlerStatusSuccess;
    }];
    [commandCenter.pauseCommand addTargetWithHandler:^MPRemoteCommandHandlerStatus(MPRemoteCommandEvent * _Nonnull event) {
        [self pausePlayback];
        return MPRemoteCommandHandlerStatusSuccess;
    }];
    [commandCenter.togglePlayPauseCommand addTargetWithHandler:^MPRemoteCommandHandlerStatus(MPRemoteCommandEvent * _Nonnull event) {
        [self togglePlayback];
        return MPRemoteCommandHandlerStatusSuccess;
    }];
}

- (void)endSession {
    // Stop playback
    if (self.speechSynthesizer.speaking) {
        [self.speechSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
    }
    self.speechSynthesizer = nil;

    // Stop audio session
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setActive:NO error:nil];
    
    MPRemoteCommandCenter *commandCenter = [MPRemoteCommandCenter sharedCommandCenter];
    [commandCenter.playCommand removeTarget:self];
    [commandCenter.pauseCommand removeTarget:self];
    [commandCenter.togglePlayPauseCommand removeTarget:self];
    
    [[UIApplication sharedApplication] endReceivingRemoteControlEvents];
    [[MPNowPlayingInfoCenter defaultCenter] setNowPlayingInfo:nil];

    // Cleanup
    self.prayer = nil;
    self.prayerText = nil;
    self.speechState = BRSpeechDisabled;
}

- (void)startPlayback {
    if (self.speechState == BRSpeechDisabled) {
        [self setState:BRSpeechStarting];

        // Generate HTML
        NSString *body = [self.prayer bodyForSpeechSynthesis];
        NSString *html =
        [NSString stringWithFormat:
         @"<head>\n"
         "  <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>\n"
         "  <link rel='stylesheet' type='text/css' href='html/breviar.css'>\n"
         "  <link rel='stylesheet' type='text/css' href='html/breviar-blind-friendly.css'>\n"
         "  <link rel='stylesheet' type='text/css' href='html/breviar-voice-output.css'>\n"
         "</head>\n"
         "<body>%@\n</body>",
         body];

        NSURL *baseURL = [NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
        [self.webView loadHTMLString:html baseURL:baseURL];
    } else if (self.speechState == BRSpeechPaused) {
        [self setState:BRSpeechPlaying];
        [self.speechSynthesizer continueSpeaking];
    } else {
        NSLog(@"Invalid state for startPlayback: %d", self.speechState);
    }
}

- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    [self.webView evaluateJavaScript:@"(function (){ return document.body.innerText; })();" completionHandler:^(id _Nullable result, NSError * _Nullable error) {
        if (error != nil || result == nil) {
            NSLog(@"Could not evaluate JavaScript. Error: %@", error);
            return;
        }
        self.prayerText = (NSString *)result;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self startSpeech];
        });
    }];
}

- (void)startSpeech {
    if (self.speechState != BRSpeechStarting) {
        NSLog(@"Invalid state for startSpeech: %d", self.speechState);
        return;
    }
    
    NSString *selectedLanguage = [[BRSettings instance] stringForOption:@"j"];
    NSDictionary *voiceCodes = @{
        @"sk": @"sk-SK",
        @"cz": @"cs-CZ",
        @"c2": @"cs-CZ",
        @"hu": @"hu-HU",
    };
    NSString *voiceCode = voiceCodes[selectedLanguage];
    if (!voiceCode) {
        voiceCode = @"sk-SK";
    }
    
    AVSpeechSynthesisVoice *voice = [AVSpeechSynthesisVoice voiceWithLanguage:voiceCode];
    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:self.prayerText];
    utterance.voice = voice;
    
    NSString *speechRate = [[BRSettings instance] stringForOption:@"speechRate"];
    if ([speechRate isEqualToString:@"verySlow"]) {
        utterance.rate = (AVSpeechUtteranceMinimumSpeechRate * 3 + AVSpeechUtteranceMaximumSpeechRate * 1) / 4;
    } else if ([speechRate isEqualToString:@"slow"]) {
        utterance.rate = (AVSpeechUtteranceMinimumSpeechRate * 2 + AVSpeechUtteranceMaximumSpeechRate * 1) / 3;
    } else if ([speechRate isEqualToString:@"fast"]) {
        utterance.rate = (AVSpeechUtteranceMinimumSpeechRate * 3 + AVSpeechUtteranceMaximumSpeechRate * 4) / 7;
    } else if ([speechRate isEqualToString:@"veryFast"]) {
        utterance.rate = (AVSpeechUtteranceMinimumSpeechRate * 1 + AVSpeechUtteranceMaximumSpeechRate * 3) / 4;
    } else {
        utterance.rate = (AVSpeechUtteranceMinimumSpeechRate * 1 + AVSpeechUtteranceMaximumSpeechRate * 1) / 2;
    }
    
    self.speechSynthesizer = [[AVSpeechSynthesizer alloc] init];
    
    [[MPNowPlayingInfoCenter defaultCenter] setNowPlayingInfo:@{
        MPMediaItemPropertyArtist: [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"],
        MPMediaItemPropertyTitle: self.prayer.title,
    }];
    
    [self setState:BRSpeechPlaying];
    [self.speechSynthesizer speakUtterance:utterance];
}

- (void)pausePlayback {
    if (self.speechState != BRSpeechStarting && self.speechState != BRSpeechPlaying) {
        NSLog(@"Invalid state for pausePlayback: %d", self.speechState);
        return;
    }
    [self setState:BRSpeechPaused];
    [self.speechSynthesizer pauseSpeakingAtBoundary:AVSpeechBoundaryImmediate];
}

- (void)togglePlayback {
    switch (self.speechState) {
        case BRSpeechDisabled:
        case BRSpeechPaused:
            [self startPlayback];
            break;
        case BRSpeechStarting:
        case BRSpeechPlaying:
            [self pausePlayback];
            break;
    }
}

- (void)resetText {
    NSLog(@"BRSpeechController / resetText");
    switch (self.speechState) {
        case BRSpeechDisabled:
            break;
        case BRSpeechPaused:
            [self.speechSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
            self.prayerText = nil;
            [self setState:BRSpeechDisabled];
            break;
        default:
            NSLog(@"Invalid state for resetText: %d", self.speechState);
            break;
    }
}

- (void)setState:(BRSpeechState)newState {
    if (newState != self.speechState) {
        self.speechState = newState;
        [self.delegate speechStateChanged:newState];
    }
}

@end
