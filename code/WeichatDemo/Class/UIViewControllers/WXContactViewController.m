//
//  WXContactViewController.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXContactViewController.h"
#import "WXContactView.h"

@interface WXContactViewController ()

@end

@implementation WXContactViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationController.title = @"通讯录";
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.view addSubview:self.contactView];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}

- (WXContactView *)contactView {
    if (_contactView == nil) {
        _contactView = [[WXContactView alloc] init];
    }

    return _contactView;
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
