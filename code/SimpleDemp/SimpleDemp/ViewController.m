//
//  ViewController.m
//  SimpleDemp
//
//  Created by blackcater on 16/6/22.
//  Copyright (c) 2016 blackcater. All rights reserved.
//


#import "ViewController.h"


@interface ViewController ()

@property(nonatomic, strong) UILabel *textLabel;
@property(nonatomic, strong) UIButton *loginBtn;
@property(nonatomic, strong) UIButton *logoutBtn;

@end

@implementation ViewController

static NSUInteger tag = 0;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.view.backgroundColor = [UIColor colorWithRed:0.9 green:0.9 blue:0.9 alpha:1.0];
    [self render];
}

- (void)render {
    [self.view addSubview:self.textLabel];
    [self.view addSubview:self.loginBtn];
    [self.view addSubview:self.logoutBtn];
}

- (UILabel *)textLabel {
    if (_textLabel == nil) {
        _textLabel = [[UILabel alloc] initWithFrame: CGRectMake(100, 200, 200, 50)];
        _textLabel.text = @"Hello World";
        _textLabel.font = [UIFont fontWithName:@"Helvetica" size:24];
        _textLabel.textAlignment = NSTextAlignmentCenter;
        [_textLabel setTextColor:[UIColor colorWithRed:0.133 green:0.192 blue:0.247 alpha:1.0]];
    }

    return _textLabel;
}

- (UIButton *)loginBtn {
    if (_loginBtn == nil) {
        _loginBtn = [self getButtonWithTitle:@"登录" andCGRect:CGRectMake(100, 540, 200, 44)];
        // 设置背景颜色
        _loginBtn.backgroundColor = [UIColor colorWithRed:0.102 green:0.737 blue:0.612 alpha:1.0];
        // 添加标识符
        [_loginBtn setTag:++tag];
        // 添加事件监听
        [_loginBtn addTarget:self action:@selector(btnClickHandler:) forControlEvents: UIControlEventTouchUpInside];
    }

    return _loginBtn;
}

- (UIButton *)logoutBtn {
    if (_logoutBtn == nil) {
        _logoutBtn = [self getButtonWithTitle:@"登出" andCGRect:CGRectMake(100, 600, 200, 44)];
        // 设置背景颜色
        _logoutBtn.backgroundColor = [UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0];
        // 添加标识符
        [_logoutBtn setTag:++tag];
        // 添加事件监听
        [_logoutBtn addTarget:self action:@selector(btnClickHandler:) forControlEvents: UIControlEventTouchUpInside];
    }

    return _logoutBtn;
}

- (void)btnClickHandler:(id) sender {
    // 健壮性
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        UIButton  *btn = (UIButton *)sender;
        switch (btn.tag) {
            case 1:
            {
                self.textLabel.text = @"登录成功";
            }
                break;
            case 2:
            {
                self.textLabel.text = @"Hello World";
            }
                break;
            default:
                break;
        }

    }
}


- (UIButton *) getButtonWithTitle:(NSString *)title andCGRect:(CGRect) rect {

    UIButton *btn = [[UIButton alloc] initWithFrame:rect];

    [btn.layer setCornerRadius:22.0];

    [btn setTitle:title forState:UIControlStateNormal];

    [btn setTitleColor:[UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:1.0] forState:UIControlStateNormal];


    return btn;
}

@end