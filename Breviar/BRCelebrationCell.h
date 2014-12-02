//
//  BRCelebrationCell.h
//  Breviar
//
//  Created by Gyimesi Akos on 1/12/13.
//
//

#import <UIKit/UIKit.h>

@class BRCelebration;

@interface BRCelebrationCell : UITableViewCell

@property (strong, nonatomic) BRCelebration *celebration;
@property (assign, nonatomic) BOOL checked;

@end
