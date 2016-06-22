//
//  ViewController.m
//  LoginDemo
//
//  Created by blackcater on 16/6/22.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#import "ViewController.h"
#import "HomeViewController.h"

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
    UIImage *img = [UIImage imageNamed:@"STARTIMAGE.jpg"];
    CGSize cgSize = {400, 700};
    self.view.backgroundColor = [UIColor colorWithPatternImage:[self OriginImage:img scaleToSize:cgSize]];
    [self render];
}

- (void)render {
    [self.view addSubview:self.textLabel];
    [self.view addSubview:self.loginBtn];
    [self.view addSubview:self.logoutBtn];
}

- (UILabel *)textLabel {
    if (_textLabel == nil) {
        _textLabel = [[UILabel alloc] initWithFrame: CGRectMake(50, 200, 300, 50)];
        _textLabel.text = @"Hello World";
        _textLabel.font = [UIFont fontWithName:@"Helvetica" size:24];
        _textLabel.textAlignment = NSTextAlignmentCenter;
        [_textLabel setTextColor:[UIColor colorWithRed:0.133 green:0.192 blue:0.247 alpha:1.0]];
    }

    return _textLabel;
}

- (UIButton *)loginBtn {
    if (_loginBtn == nil) {
        _loginBtn = [self getButtonWithTitle:@"登录" andCGRect:CGRectMake(50, 540, 300, 44)];
        // 设置背景颜色
        _loginBtn.layer.borderWidth = 2;
        _loginBtn.layer.borderColor = [UIColor colorWithRed:0.102 green:0.737 blue:0.612 alpha:1.0].CGColor;
        [_loginBtn setTitleColor:[UIColor colorWithRed:0.102 green:0.737 blue:0.612 alpha:1.0] forState:UIControlStateNormal];
        // 添加标识符
        [_loginBtn setTag:++tag];
        // 添加事件监听
        [_loginBtn addTarget:self action:@selector(btnDownClickHandler:) forControlEvents: UIControlEventTouchDown];
        [_loginBtn addTarget:self action:@selector(btnUpClickHandler:) forControlEvents: UIControlEventTouchUpInside];
    }

    return _loginBtn;
}

- (UIButton *)logoutBtn {
    if (_logoutBtn == nil) {
        _logoutBtn = [self getButtonWithTitle:@"登出" andCGRect:CGRectMake(50, 600, 300, 44)];
        // 设置背景颜色
        // _logoutBtn.backgroundColor = [UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0];
        // 设置边框
        _logoutBtn.layer.borderWidth = 2;
        _logoutBtn.layer.borderColor = [UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0].CGColor;
        [_logoutBtn setTitleColor:[UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0] forState:UIControlStateNormal];
        // 添加标识符
        [_logoutBtn setTag:++tag];
        // 添加事件监听
        [_logoutBtn addTarget:self action:@selector(btnDownClickHandler:) forControlEvents: UIControlEventTouchDown];
        [_logoutBtn addTarget:self action:@selector(btnUpClickHandler:) forControlEvents:UIControlEventTouchUpInside];
    }

    return _logoutBtn;
}

- (void)btnDownClickHandler:(id) sender {
    // 健壮性
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        UIButton  *btn = (UIButton *)sender;
        switch (btn.tag) {
            case 1:
            {
                self.loginBtn.backgroundColor = [UIColor colorWithRed:0.102 green:0.737 blue:0.612 alpha:1.0];
                [self.loginBtn setTitleColor:[UIColor colorWithRed:1 green:1 blue:1 alpha:1] forState:UIControlStateNormal];
                self.textLabel.text = @"登录成功";
            }
                break;
            case 2:
            {
                self.logoutBtn.backgroundColor = [UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0];
                [self.logoutBtn setTitleColor:[UIColor colorWithRed:1 green:1 blue:1 alpha:1] forState:UIControlStateNormal];
                self.textLabel.text = @"Hello World";
            }
                break;
            default:
                break;
        }

    }
}

- (void)btnUpClickHandler:(id) sender {
    // 健壮性
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        UIButton  *btn = (UIButton *)sender;
        switch (btn.tag) {
            case 1:
            {
                self.loginBtn.backgroundColor = [UIColor colorWithRed:1 green:1 blue:1 alpha:0];
                [self.loginBtn setTitleColor:[UIColor colorWithRed:0.102 green:0.737 blue:0.612 alpha:1.0] forState:UIControlStateNormal];
//                [self.navigationController pushViewController:[[HomeViewController alloc] init] animated:YES];
                [self presentViewController:[[HomeViewController alloc] init] animated:YES completion:nil];
            }
                break;
            case 2:
            {
                self.logoutBtn.backgroundColor = [UIColor colorWithRed:1 green:1 blue:1 alpha:0];
                [self.logoutBtn setTitleColor:[UIColor colorWithRed:0.953 green:0.612 blue:0.07 alpha:1.0] forState:UIControlStateNormal];
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

    return btn;
}

-(UIImage*) OriginImage:(UIImage *)image scaleToSize:(CGSize)size
{
    UIGraphicsBeginImageContext(size);  //size 为CGSize类型，即你所需要的图片尺寸

    [image drawInRect:CGRectMake(0, 0, size.width, size.height)];

    UIImage* scaledImage = UIGraphicsGetImageFromCurrentImageContext();

    UIGraphicsEndImageContext();

    return scaledImage;   //返回的就是已经改变的图片
}

@end
