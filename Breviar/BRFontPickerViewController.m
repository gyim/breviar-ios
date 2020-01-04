//
//  BRFontPickerViewController.m
//  Breviar
//
//  Created by Gyimesi Akos on 9/8/12.
//
//

#import "BRFontPickerViewController.h"
#import "BRFontHelper.h"

typedef enum {
    BRFontFamilyComponent = 0,
    BRFontSizeComponent = 1
} BRFontPickerComponent;

static CGFloat componentSizes[] = {
    200,
    80
};

@interface BRFontPickerViewController ()

@property(strong) IBOutlet UIWebView *webView;
@property(strong) IBOutlet UIPickerView *pickerView;

@end

@implementation BRFontPickerViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    // Select current font in picker
    NSUInteger familyIndex = [[BRFontHelper instance].availableFonts indexOfObject:self.fontFamily];
    if (familyIndex != NSNotFound) {
        [self.pickerView selectRow:familyIndex inComponent:BRFontFamilyComponent animated:NO];
    }
    NSUInteger sizeIndex = [[BRFontHelper instance].availableSizes indexOfObject:@(self.fontSize)];
    if (sizeIndex != NSNotFound) {
        [self.pickerView selectRow:sizeIndex inComponent:BRFontSizeComponent animated:NO];
    }
    
    [self updatePreview];
}

- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection
{
    [super traitCollectionDidChange: previousTraitCollection];
    if (@available(iOS 12.0, *)) {
        if (previousTraitCollection.userInterfaceStyle != self.traitCollection.userInterfaceStyle) {
            [self updatePreview];
        }
    }
}

#pragma mark -
#pragma mark UIPickerViewDataSource

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 2;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    if (component == BRFontFamilyComponent) {
        return [BRFontHelper instance].availableFonts.count;
    }
    else if (component == BRFontSizeComponent) {
        return [BRFontHelper instance].availableSizes.count;
    }
    return 0;
}

#pragma mark -
#pragma mark UIPickerViewDelegate

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    BRFontHelper *fontHelper = [BRFontHelper instance];
    
    if (component == BRFontFamilyComponent) {
        NSString *fontFamily = [fontHelper.availableFonts objectAtIndex:row];
        NSString *fontName = [fontHelper fontNameForFamily:fontFamily];
        return fontName;
    }
    else if (component == BRFontSizeComponent) {
        return [NSString stringWithFormat:@"%@ px", [fontHelper.availableSizes objectAtIndex:row]];
    }
    return nil;
}

- (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component {
    return componentSizes[component];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    BRFontHelper *fontHelper = [BRFontHelper instance];
    
    if (component == BRFontFamilyComponent) {
        self.fontFamily = [fontHelper.availableFonts objectAtIndex:row];
    }
    else if (component == BRFontSizeComponent) {
        self.fontSize = [[fontHelper.availableSizes objectAtIndex:row] intValue];
    }
    
    [self.delegate fontPicker:self didPickFontFamily:self.fontFamily size:self.fontSize];
    [self updatePreview];
}

#pragma mark -
#pragma mark Preview

- (void)updatePreview {
    NSString *bgColor = @"white";
    NSString *fgColor = @"black";
    
    if (@available(iOS 12.0, *)) {
        if (self.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark) {
            bgColor = @"black";
            fgColor = @"white";
        }
    }
    
    NSString *html = [NSString stringWithFormat:
                      @"<!DOCTYPE html>\n"
                      "<html><body>"
                      "<body style='background: %@; color: %@; font-size: %ldpx; font-family: %@; -webkit-text-size-adjust: none;'>"
                      "<p>Te Deum laudamus:<br>te Dominum confitemur.<br>Te aeternum Patrem<br>omnis terra veneratur.<br>Tibi omnes Angeli; tibi caeli et universae Potestates;<br>Tibi Cherubim et Seraphim<br>incessabili voce proclamant:<br>Sanctus, Sanctus, Sanctus, Dominus Deus Sabaoth.</p>"
                      "</body></html>",
                      bgColor, fgColor,
                      (long)self.fontSize, self.fontFamily];
    [self.webView loadHTMLString:html baseURL:[NSURL URLWithString:@"http://breviar.sk"]];
}

#pragma mark -
#pragma mark Actions

- (IBAction)donePressed:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
