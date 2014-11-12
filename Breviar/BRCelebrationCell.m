//
//  BRCelebrationCell.m
//  Breviar
//
//  Created by Gyimesi Akos on 1/12/13.
//
//

#import "BRCelebrationCell.h"

@implementation BRCelebrationCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    // This makes sense for iPhone only; iPad cells are wide enough. If not, calculate left+right margins for iPad here:
    CGFloat margins = 74;
    
    self.celebrationNameLabel.preferredMaxLayoutWidth = CGRectGetWidth(self.bounds) - margins;
    self.celebrationDescriptionLabel.preferredMaxLayoutWidth = CGRectGetWidth(self.bounds) - margins;
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
