//
//  MainBottomControlView.m
//  Homework_UI_Day2_2
//
//  Created by blackcater on 16/6/27.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "MainBottomControlView.h"

@interface MainBottomControlView()

@property (nonatomic, strong) UIButton *preBtn;
@property (nonatomic, strong) UIButton *pauseBtn;
@property (nonatomic, strong) UIButton *postBtn;
@property (nonatomic, strong) UISlider *slider;

@end

@implementation MainBottomControlView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];

    if (self) {
        [self render];
    }

    return self;
}

- (void)render {
    [self addSubview:self.slider];
    [self addSubview:self.preBtn];
    [self addSubview:self.pauseBtn];
    [self addSubview:self.postBtn];
}

- (UISlider *)slider {
    if (_slider == nil) {
        _slider = [[UISlider alloc] initWithFrame:CGRectMake(0, (self.frame.size.height-40), SCREEN_WIDTH, 35)];

        _slider.maximumValue = 1.0;
        _slider.minimumValue = 0.0;

        [_slider setMinimumTrackImage:[UIImage imageNamed:@"gress-bar-active.png"] forState:UIControlStateNormal];
        [_slider setMaximumTrackImage:[UIImage imageNamed:@"gress-bar.png"] forState:UIControlStateNormal];
        [_slider setThumbImage:[UIImage imageNamed:@"gress-btn.png"] forState:UIControlStateNormal];
    }

    return _slider;
}

- (UIButton *)preBtn {
    if (_preBtn == nil) {
        _preBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, (self.frame.size.height-80), 30, 30)];
        [_preBtn setImage:[self OriginImage:[UIImage imageNamed:@"ios7-rewind.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _preBtn;
}

- (UIButton *)pauseBtn {
    if (_pauseBtn == nil) {
        _pauseBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-30)/2, (self.frame.size.height-80), 30, 30)];
        [_pauseBtn setImage:[self OriginImage:[UIImage imageNamed:@"pause.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _pauseBtn;
}

- (UIButton *)postBtn {
    if (_postBtn == nil) {
        _postBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-40), (self.frame.size.height-80), 30, 30)];
        [_postBtn setImage:[self OriginImage:[UIImage imageNamed:@"ios7-fastforward.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
    }

    return _postBtn;
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
