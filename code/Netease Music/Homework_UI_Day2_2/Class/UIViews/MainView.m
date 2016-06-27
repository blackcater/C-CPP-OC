//
//  MainView.m
//  Homework_UI_Day2_2
//
//  Created by blackcater on 16/6/27.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "MainView.h"
#import "MainTopBarView.h"
#import "MainTopControlView.h"
#import "MainBottomControlView.h"

@interface MainView()
@property (nonatomic, strong) MainTopBarView *topBar;
@property (nonatomic, strong) MainTopControlView *topControl;
@property (nonatomic, strong) UIImageView *album;
@property (nonatomic, strong) MainBottomControlView *bottomControl;
@end

@implementation MainView

- (instancetype) init {
    self = [super init];
    if (self) {
        self.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        self.backgroundColor = [UIColor whiteColor];

        [self render];
    }

    return self;
}

- (void)render {
    [self renderAlbum];
    [self addSubview:self.topBar];
    [self addSubview:self.topControl];
    [self addSubview:self.bottomControl];
}

- (void)renderAlbum {

    self.album = [[UIImageView alloc] initWithImage:[self OriginImage:[UIImage imageNamed:@"avatar.png"] scaleToSize:CGSizeMake(220, 220)]];
    self.album.frame = CGRectMake((SCREEN_WIDTH-220)/2, 220, 220, 220);

    UIView *maskview = [[UIView alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-220)/2, 220, 220, 220)];
    [maskview setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"cm2_play_disc_radio_bg.png"]]];

    UIView *radioview = [[UIView alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-238)/2, 220, 238, 238)];
    [radioview setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"cm2_play_disc.png"]]];

    [self addSubview:maskview];
    [self addSubview:self.album];
    [self addSubview:radioview];
}

- (MainTopBarView *)topBar {
    if (_topBar == nil) {
        _topBar = [[MainTopBarView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, 60)];
        _topBar.backgroundColor = COLOR_RGB(212, 60, 51);
    }
    return _topBar;
}

- (MainTopControlView *)topControl {
    if (_topControl == nil) {
        _topControl = [[MainTopControlView alloc] initWithFrame:CGRectMake(0, self.topBar.frame.size.height, SCREEN_WIDTH, 80)];
        _topControl.backgroundColor = COLOR_RGB(56, 56, 57);
    }

    return _topControl;
}

- (MainBottomControlView *)bottomControl {
    if (_bottomControl == nil) {
        _bottomControl = [[MainBottomControlView alloc] initWithFrame:CGRectMake(0, (SCREEN_HEIGHT-100), SCREEN_WIDTH, 100)];
        _bottomControl.backgroundColor = COLOR_RGB(56, 56, 57);
    }

    return _bottomControl;
}

-(UIImage*) OriginImage:(UIImage *)image scaleToSize:(CGSize)size
{
    UIGraphicsBeginImageContext(size);  //size 为CGSize类型，即你所需要的图片尺寸

    [image drawInRect:CGRectMake(0, 0, size.width, size.height)];

    UIImage* scaledImage = UIGraphicsGetImageFromCurrentImageContext();

    UIGraphicsEndImageContext();

    return scaledImage;   //返回的就是已经改变的图片
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
