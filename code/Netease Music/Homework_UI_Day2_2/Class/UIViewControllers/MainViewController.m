//
//  MainViewController.m
//  Homework_UI_Day2_2
//
//  Created by blackcater on 16/6/27.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "MainViewController.h"
#import "MainView.h"

@interface MainViewController ()

@property (nonatomic, strong) MainView *mainView;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self render];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}

- (void)render {
    [self.view addSubview:self.mainView];
}

- (MainView *)mainView {
    if (_mainView == nil) {
        _mainView = [[MainView alloc] init];
    }

    return _mainView;
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
