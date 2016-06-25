//
//  PublicDefine.h
//  WeichatDemo
//
//  Created by blackcater on 16/6/23.
//  Copyright (c) 2016 blackcater. All rights reserved.
//

#ifndef PublicDefine_h
#define PublicDefine_h

#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#define COLOR_RGB(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define COLOR_RGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

// 定义新功能介绍页的页数
#define WELCOME_IMAGE_LEN 7

// 定义新功能介绍页图片名称
#define WELCOME_FILENAME_PREFIX "cm2_guide_start"

// 1.0 版本号就是10 1.0.0版本号就是100
#define PROJECT_VERSION 10

#endif /* PublicDefine_h */
