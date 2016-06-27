//
//  MainTopControlView.m
//  Homework_UI_Day2_2
//
//  Created by blackcater on 16/6/27.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "MainTopControlView.h"

@interface MainTopControlView()

@property (nonatomic, strong) UISlider *slider;
@property (nonatomic, strong) UIButton *loopBtn;
@property (nonatomic, strong) UIButton *downloadBtn;
@property (nonatomic, strong) UIButton *playListBtn;

@end

@implementation MainTopControlView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];

    if (self) {
        [self render];
    }

    return self;
}

- (void) render {
    [self addSubview:self.slider];
    [self addSubview:self.loopBtn];
    [self addSubview:self.downloadBtn];
    [self addSubview:self.playListBtn];
}

- (UISlider *)slider {
    if (_slider == nil) {
        _slider = [[UISlider alloc] initWithFrame:CGRectMake(0, 5, SCREEN_WIDTH, 35)];

        _slider.maximumValue = 1.0;
        _slider.minimumValue = 0.0;

        [_slider setMinimumTrackImage:[UIImage imageNamed:@"gress-bar-active.png"] forState:UIControlStateNormal];
        [_slider setMaximumTrackImage:[UIImage imageNamed:@"gress-bar.png"] forState:UIControlStateNormal];
        [_slider setThumbImage:[UIImage imageNamed:@"gress-btn.png"] forState:UIControlStateNormal];
    }

    return _slider;
}

- (UIButton *)loopBtn {
    if (_loopBtn == nil) {
        _loopBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 45, 30, 30)];
        [_loopBtn setImage:[self OriginImage:[UIImage imageNamed:@"ios7-loop-strong.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _loopBtn;
}

- (UIButton *)downloadBtn {
    if (_downloadBtn == nil) {
        _downloadBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-30)/2, 45, 30, 30)];
        [_downloadBtn setImage:[self OriginImage:[UIImage imageNamed:@"ios7-download-outline.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _downloadBtn;
}

- (UIButton *)playListBtn {
    if (_playListBtn == nil) {
        _playListBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-40), 45, 30, 30)];
        [_playListBtn setImage:[self OriginImage:[UIImage imageNamed:@"android-drawer.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _playListBtn;
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
