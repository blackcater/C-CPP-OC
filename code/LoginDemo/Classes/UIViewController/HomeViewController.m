//
// Created by blackcater on 16/6/22.
// Copyright (c) 2016 blackcater. All rights reserved.
//

#import "HomeViewController.h"

@interface HomeViewController ()

@property(nonatomic, strong) UILabel *textLabel;
@property(nonatomic, strong) UIButton *downBtn;

@end

@implementation HomeViewController

static NSInteger tag = 0;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    self.view.backgroundColor = [UIColor colorWithRed:0.9 green:0.9 blue:0.9 alpha:1];
    [self render];
}

- (void)render {
    [self.view addSubview:self.downBtn];
    [self.view addSubview:self.textLabel];
}

- (UILabel *)textLabel {
    if (_textLabel == nil) {
        _textLabel = [[UILabel alloc] initWithFrame: CGRectMake(50, 200, 300, 50)];
        _textLabel.text = @"Home Page";
        _textLabel.font = [UIFont fontWithName:@"Helvetica" size:34];
        _textLabel.textAlignment = NSTextAlignmentCenter;
        [_textLabel setTextColor:[UIColor colorWithRed:0.133 green:0.192 blue:0.247 alpha:1.0]];
    }

    return _textLabel;
}

- (UIButton *)downBtn {
    if (_downBtn == nil) {
        _downBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 20, 46, 46)];

        UIImage *img = [UIImage imageNamed:@"arrow_down.png"];
        _downBtn.backgroundColor = [UIColor colorWithPatternImage:img];

        [_downBtn setTag:++tag];
        [_downBtn addTarget:self action:@selector(downBtnClickHandler:) forControlEvents:UIControlEventTouchDown];
    }

    return _downBtn;
}

- (void) downBtnClickHandler:(id)sender {
    if (sender && [sender isKindOfClass:[UIButton class]]) {
        UIButton *btn = (UIButton *)sender;

        switch (btn.tag) {
            case 1:
            {
                [self dismissViewControllerAnimated:YES completion:nil];
            }
                break;
            default:
                break;
        }
    }
}

@end