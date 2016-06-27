//
//  MainTopBarView.m
//  Homework_UI_Day2_2
//
//  Created by blackcater on 16/6/27.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "MainTopBarView.h"

@interface MainTopBarView()

@property (nonatomic, strong) UIButton *leftBtn;
@property (nonatomic, strong) UIButton *loveBtn;
@property (nonatomic, strong) UILabel *musicTitle;
@property (nonatomic, strong) UILabel *singerTitle;
@property (nonatomic, assign) BOOL flag;

@end

@implementation MainTopBarView

- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];

    if (self) {
        [self render];
    }

    return self;
}

- (void)render {
    [self addSubview:self.leftBtn];
    [self addSubview:self.loveBtn];
    [self addSubview:self.musicTitle];
    [self addSubview:self.singerTitle];
}

- (UIButton *)leftBtn {
    if (_leftBtn == nil) {
        _leftBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 20, 30, 30)];
        [_leftBtn setBackgroundImage:[self OriginImage:[UIImage imageNamed:@"arrow-left-a.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];

        _leftBtn.tag = 1;
    }

    return _leftBtn;
}

- (UIButton *)loveBtn {
    if (_loveBtn == nil) {
        _loveBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-40), 20, 30, 30)];
        [_loveBtn setImage:[self OriginImage:[UIImage imageNamed:@"android-star.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];

        self.flag = NO;

        _loveBtn.tag = 2;

        [_loveBtn addTarget:self action:@selector(loveBtnClickHandler:) forControlEvents:UIControlEventTouchUpInside];
    }

    return _loveBtn;
}

- (UILabel *)musicTitle {
    if (_musicTitle == nil) {
        _musicTitle = [[UILabel alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-200)/2, 16, 200, 24)];
        [_musicTitle setText:@"早睡身体好"];
        [_musicTitle setTextColor:[UIColor whiteColor]];
        [_musicTitle setTextAlignment:NSTextAlignmentCenter];
        [_musicTitle setFont:[UIFont systemFontOfSize:18]];
    }

    return _musicTitle;
}

- (UILabel *)singerTitle {
    if (_singerTitle == nil) {
        _singerTitle = [[UILabel alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-200)/2, CGRectGetMaxY(self.musicTitle.frame), 200, 16)];

        [_singerTitle setText:@"许嵩"];
        [_singerTitle setTextColor:[UIColor whiteColor]];
        [_singerTitle setTextAlignment:NSTextAlignmentCenter];
        [_singerTitle setFont:[UIFont systemFontOfSize:12]];
    }

    return _singerTitle;
}

- (void)loveBtnClickHandler: (id)sender {
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        UIButton *btn = (UIButton *)sender;
        switch (btn.tag) {
            case 2:
            {
                if (self.flag) {
                    self.flag = NO;
                    [btn setImage:[self OriginImage:[UIImage imageNamed:@"android-star.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
                } else {
                    self.flag = YES;
                    [btn setImage:[self OriginImage:[UIImage imageNamed:@"android-star-active.png"] scaleToSize:CGSizeMake(30, 30)] forState:UIControlStateNormal];
                }
            }
                break;
            default:
                break;
        }
    }
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
