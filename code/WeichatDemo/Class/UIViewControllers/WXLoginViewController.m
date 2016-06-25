//
//  WXLoginViewController.m
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#import "WXLoginViewController.h"
#import "WXLoginView.h"
#import "PublicDefine.h"
#import "WXHomeViewController.h"
#import "WXContactViewController.h"
#import "WXFindViewController.h"
#import "WXMineViewController.h"
#import "WXHomeView.h"

@interface WXLoginViewController ()

@end

@implementation WXLoginViewController

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

    [self.view addSubview:self.loginView];
    // 监听事件
    [self.loginView.passwordTextField addTarget:self action:@selector(passwordCheckedHandler:) forControlEvents:UIControlEventEditingChanged];
    [self.loginView.loginBtn addTarget:self action:@selector(loginBtnClickHandler:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)passwordCheckedHandler:(id)sender {
    UITextField *textField = (UITextField *)sender;
    if ([textField.text length] > 0) {
        self.loginView.loginBtn.backgroundColor = COLOR_RGBA(26, 173, 25, 1.0);
    } else {
        self.loginView.loginBtn.backgroundColor = COLOR_RGBA(26, 173, 25, 0.6);
    }
}

- (void)loginBtnClickHandler:(id)sender {
    if ([self.loginView.passwordTextField.text length] > 0) {
        if ([self.loginView.passwordTextField.text isEqualToString:@"123456"]) {
            // 页面跳转
            UITabBarController *tabBarController = [[UITabBarController alloc] init];

            UIViewController *homeC = [[WXHomeViewController alloc] init];
            UINavigationController *home = [[UINavigationController alloc] initWithRootViewController:homeC];
//            [home pushViewController:homeC animated:YES];
            homeC.title = @"微信";
            home.tabBarItem.title = @"微信";
//            home.tabBarItem.image = [UIImage imageNamed:@"video_next_button_disabled@2x.png"];
//            home.tabBarItem.selectedImage = [UIImage imageNamed:@"video_next_button@2x.png"];

            UIViewController *contactC = [[WXContactViewController alloc] init];
            UINavigationController *contact = [[UINavigationController alloc] initWithRootViewController:contactC];
//            [contact pushViewController:contactC animated:YES];
            contactC.title = @"通讯录";
            contact.tabBarItem.title = @"通讯录";

            UIViewController *findC = [[WXFindViewController alloc] init];
            UINavigationController *find = [[UINavigationController alloc] initWithRootViewController:findC];
//            [find pushViewController:findC animated:YES];
            findC.title = @"发现";
            find.tabBarItem.title = @"发现";
            find.tabBarItem.badgeValue = @"new";
            find.tabBarItem.image = [UIImage imageNamed:@"userinfo_tabicon_search@2x.png"];
            find.tabBarItem.selectedImage = [[UIImage imageNamed:@"userinfo_tabicon_search_highlighted@2x.png"] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];

            UIViewController *mineC = [[WXMineViewController alloc] init];
            UINavigationController *mine = [[UINavigationController alloc] initWithRootViewController:mineC];
//            [mine pushViewController:mineC animated:YES];
            mineC.title = @"我";
            mine.tabBarItem.title = @"我";

            NSArray *viewControllers = @[home, contact, find, mine];

//            tabBarController.tabBarItem

            tabBarController.viewControllers = viewControllers;

//            [tabBarController setViewControllers:viewControllers animated:YES];

            [UIApplication sharedApplication].keyWindow.rootViewController = tabBarController;

        }
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}



- (WXLoginView *)loginView {
    if (_loginView == nil) {
        _loginView = [[WXLoginView alloc] init];
    }

    return _loginView;
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
