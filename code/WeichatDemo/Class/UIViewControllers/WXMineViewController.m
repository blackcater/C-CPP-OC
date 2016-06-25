//
//  WXMineViewController.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXMineViewController.h"
#import "WXMineView.h"

@interface WXMineViewController ()

@end

@implementation WXMineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"我";
    UIImage *navigationBarImg = [UIImage imageNamed:@"bar.png"];
    [self.navigationController.navigationBar setBackgroundImage:navigationBarImg forBarMetrics:UIBarMetricsDefault];
    self.navigationController.navigationBar.tintColor = [UIColor whiteColor];
    [self.navigationController.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor]}];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.view addSubview:self.mineView];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}

- (WXMineView *)mineView {
    if (_mineView == nil) {
        _mineView = [[WXMineView alloc] init];
    }

    return _mineView;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
