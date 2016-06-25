//
//  WXIntroduceView.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/25.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXIntroduceView.h"

@interface WXIntroduceView() <UIScrollViewDelegate>
@end

@implementation WXIntroduceView

- (instancetype)init {
    self = [super init];

    if (self) {
        self.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        self.backgroundColor = [UIColor whiteColor];

        [self render];
    }

    return self;
}

- (void)render {
    [self addSubview:self.scrollView];
    [self addSubview:self.pageControl];
}

- (UIScrollView *)scrollView {
    if (_scrollView == nil) {
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)];
        // 关闭滚动条
        _scrollView.showsHorizontalScrollIndicator = NO;
        _scrollView.showsVerticalScrollIndicator = NO;

        _scrollView.contentSize = CGSizeMake(SCREEN_WIDTH*WELCOME_IMAGE_LEN, SCREEN_HEIGHT);
        _scrollView.contentOffset = CGPointZero;
        // 设置可以分页
        _scrollView.pagingEnabled = YES;
        // 禁止缩放
        _scrollView.minimumZoomScale = 1.0;
        _scrollView.maximumZoomScale = 1.0;
        // 禁止边界动画
        _scrollView.bounces = NO;
        // 设置代理
        _scrollView.delegate = self;

        [self addImagesToScrollView];
    }

    return _scrollView;
}

- (UIPageControl *)pageControl {
    if (_pageControl == nil) {
        _pageControl = [[UIPageControl alloc] init];
        _pageControl.frame = CGRectMake((SCREEN_WIDTH-300)/2, (SCREEN_HEIGHT-15), 300, 10);
        _pageControl.numberOfPages = WELCOME_IMAGE_LEN;
        _pageControl.currentPage = 0;
        _pageControl.pageIndicatorTintColor = COLOR_RGB(200, 200, 200);
        _pageControl.currentPageIndicatorTintColor = COLOR_RGB(205, 51, 51);
    }

    return _pageControl;
}

// 向scrollView中添加新功能介绍页面图片
- (void)addImagesToScrollView {
    int len = WELCOME_IMAGE_LEN;

    for (int i = 0; i < len; ++i) {
        UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"%s%d.png", WELCOME_FILENAME_PREFIX, (i+1)]];
        UIImageView *imageView = [[UIImageView alloc] initWithImage: image];
        imageView.frame = CGRectMake(SCREEN_WIDTH*i, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        // 如果是最后一张
        if (i == (len - 1)) {
            imageView.userInteractionEnabled = YES;
            [self renderLastWelcomeImageView:imageView];
        }

        [self.scrollView addSubview:imageView];
    }
}

// 向最后一张imageView中添加一些元素
- (void)renderLastWelcomeImageView:(UIImageView *)imageView {
    UIButton *welcomeBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-300)/2, (SCREEN_HEIGHT-44-30), 296, 40)];
    // 设置边框
    welcomeBtn.layer.borderColor = COLOR_RGB(205, 51, 51).CGColor;
    welcomeBtn.layer.borderWidth = 2;
    welcomeBtn.layer.cornerRadius = 20;
    // 设置文本
    [welcomeBtn setTitle:@"立即体验" forState:UIControlStateNormal];
    [welcomeBtn setTitleColor:COLOR_RGB(205, 51, 51) forState:UIControlStateNormal];

    // 添加监听
    [welcomeBtn addTarget:self action:@selector(welcomeBtnClickHandler:) forControlEvents:UIControlEventTouchUpInside];

    // 添加label
    UIImage *startImage = [UIImage imageNamed:@"cm2_shareview_logo.jpg"];
    UIImageView *startImageView = [[UIImageView alloc] initWithImage:startImage];
    startImageView.frame = CGRectMake((SCREEN_WIDTH-210), 0, 210, 320);

    [imageView addSubview:startImageView];
    [imageView addSubview:welcomeBtn];
}
- (void)welcomeBtnClickHandler:(id)sender {
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        // 设置变化效果
        [UIView animateWithDuration:1.0 delay:0.0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
            self.alpha = 0.0;
        } completion:^(BOOL f){
            // 完成之后 删除视图
            [self removeFromSuperview];
        }];
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView{

    int index = (int)floor(scrollView.contentOffset.x / SCREEN_WIDTH);

    _pageControl.currentPage = index;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
