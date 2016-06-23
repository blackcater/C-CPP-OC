//
//  WXFindView.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXFindView.h"
#import "PublicDefine.h"

@implementation WXFindView

-(instancetype)init {
    self = [super init];

    if (self) {
        self.backgroundColor = [UIColor blueColor];
        self.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
