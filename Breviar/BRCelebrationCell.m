//
//  BRCelebrationCell.m
//  Breviar
//
//  Created by Gyimesi Akos on 1/12/13.
//
//

#import "BRCelebrationCell.h"
#import "BRCelebration.h"

static NSString *liturgicalColorImages[] = {
    [BRColorUnknown]       = @"",
    [BRColorRed]           = @"bullet_red.png",
    [BRColorWhite]         = @"bullet_white.png",
    [BRColorGreen]         = @"bullet_green.png",
    [BRColorViolet]        = @"bullet_violet.png",
    [BRColorRose]          = @"bullet_rose.png",
    [BRColorBlack]         = @"bullet_black.png",
    [BRColorVioletOrBlack] = @"bullet_violet_or_black.png",
    [BRColorVioletOrWhite] = @"bullet_violet_or_white.png",
    [BRColorRoseOrViolet]  = @"bullet_rose_or_violet.png"
};


@interface BRCelebrationCell ()

@property (weak, nonatomic) IBOutlet UILabel *celebrationNameLabel;
@property (weak, nonatomic) IBOutlet UILabel *celebrationDescriptionLabel;
@property (weak, nonatomic) IBOutlet UIImageView *liturgicalColorView;

@end


@implementation BRCelebrationCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    // This makes sense for iPhone only; iPad cells are wide enough. If not, calculate left+right margins for iPad here:
    CGFloat margins = 74;
    
    self.celebrationNameLabel.preferredMaxLayoutWidth = CGRectGetWidth(self.bounds) - margins;
    self.celebrationDescriptionLabel.preferredMaxLayoutWidth = CGRectGetWidth(self.bounds) - margins;
}

- (void)setCelebration:(BRCelebration *)celebration
{
    _celebration = celebration;
    
    // Replace spaces after dots with non-breakable space so that "St. Peter" or "24. tyzden" won't get split at the end of line
    NSString *title = [celebration.title stringByReplacingOccurrencesOfString:@". " withString:@". "];
    
    self.celebrationNameLabel.text = title;
    self.celebrationDescriptionLabel.text = celebration.subtitle;
    self.liturgicalColorView.image = [UIImage imageNamed:liturgicalColorImages[celebration.liturgicalColor]];
}

- (void)setChecked:(BOOL)checked
{
    _checked = checked;
    
    if (checked) {
        self.accessoryView = nil;
        self.accessoryType = UITableViewCellAccessoryCheckmark;
    } else {
        // Unchecked cell needs at least an empty view as a placeholder to keep width of the labels correct. I admit this isn't the nicest solution, but it works.
        self.accessoryType = UITableViewCellAccessoryNone;
        self.accessoryView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 24, 10)];
    }
}

@end
