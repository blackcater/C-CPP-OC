//
//  WXLoginView.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXLoginView.h"
#import "PublicDefine.h"

@interface WXLoginView()

@property (nonatomic, strong) UIView *underline;

@end

@implementation WXLoginView

- (UIImageView *)avatar {
    if (_avatar == nil) {
        _avatar = [[UIImageView alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-62)/2, 60, 60, 60)];
        [_avatar setImage:[UIImage imageNamed:@"avatar.png"]];
        _avatar.layer.borderWidth = 1;
        _avatar.layer.borderColor = COLOR_RGB(240, 240, 240).CGColor;
    }

    return _avatar;
}

- (UILabel *)phoneLabel {
    if (_phoneLabel == nil) {
        _phoneLabel = [[UILabel alloc] initWithFrame: CGRectMake((SCREEN_WIDTH-200)/2, CGRectGetMaxY(self.avatar.frame)+10, 200, 30)];
        _phoneLabel.text = @"+86 182 0242 8039";
        _phoneLabel.textAlignment = NSTextAlignmentCenter;
    }

    return _phoneLabel;
}

- (UILabel *)passwordLabel {
    if (_passwordLabel == nil) {
        _passwordLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, CGRectGetMaxY(self.phoneLabel.frame)+20, 40, 28)];
        _passwordLabel.text = @"密码";
        _passwordLabel.textAlignment = NSTextAlignmentCenter;
    }

    return _passwordLabel;
}

- (UITextField *)passwordTextField {
    if (_passwordTextField == nil) {
//        CGRectMake(150, CGRectGetMaxY(self.phoneLabel.frame)+20, SCREEN_WIDTH-150, 30)
        _passwordTextField = [[UITextField alloc] initWithFrame:CGRectMake(110, CGRectGetMaxY(self.phoneLabel.frame)+20, SCREEN_WIDTH-150, 30)];
        _passwordTextField.placeholder = @"请填写密码";
        _passwordTextField.secureTextEntry = YES;
    }

    return _passwordTextField;
}

- (UIView *)underline {
    if (_underline == nil) {
        _underline = [[UIView alloc] initWithFrame:CGRectMake(10, CGRectGetMaxY(self.passwordTextField.frame), SCREEN_WIDTH-10, 1)];
        _underline.backgroundColor = COLOR_RGB(240, 240, 240);
    }

    return _underline;
}

- (UIButton *)loginBtn {
    if (_loginBtn == nil) {
        _loginBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, CGRectGetMaxY(self.underline.frame)+20, SCREEN_WIDTH-20, 40)];
        _loginBtn.backgroundColor = COLOR_RGBA(26, 173, 25, 0.6);
        _loginBtn.layer.cornerRadius = 8;
        [_loginBtn setTitle:@"登录" forState:UIControlStateNormal];
        [_loginBtn setTitleColor:[UIColor whiteColor]forState:UIControlStateNormal];
    }

    return _loginBtn;
}

- (UIButton *)questionBtn {
    if (_questionBtn == nil) {
        _questionBtn = [[UIButton alloc] initWithFrame:CGRectMake((SCREEN_WIDTH-200)/2, CGRectGetMaxY(self.loginBtn.frame)+15, 200, 15)];
        [_questionBtn setTitle:@"登录遇到问题?" forState:UIControlStateNormal];
        [_questionBtn setTitleColor:COLOR_RGB(91, 111, 153) forState:UIControlStateNormal];
        [_questionBtn setFont:[UIFont systemFontOfSize:12]];
    }

    return _questionBtn;
}

- (instancetype)init {
    self = [super init];

    if ( self ) {
        [self render];
        self.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        self.backgroundColor = [UIColor whiteColor];
    }

    return self;
}

- (void) render {
    [self addSubview:self.avatar];
    [self addSubview:self.phoneLabel];
    [self addSubview:self.passwordLabel];
    [self addSubview:self.passwordTextField];
    [self addSubview:self.underline];
    [self addSubview:self.loginBtn];
    [self addSubview:self.questionBtn];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
