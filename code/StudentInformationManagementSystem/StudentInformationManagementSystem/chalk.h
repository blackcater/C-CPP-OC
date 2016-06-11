//
//  chalk.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef chalk_h
#define chalk_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// -----------------------------------------------------------------
/*
 *                    定义一些常量
 */
// -----------------------------------------------------------------
#define CHALK_START      "\e["
#define CHALK_END        "m"
#define CHALK_ATTR_CLOSE "\e[0m"
#define CHALK_HIGHLIGHT  "\e[1m"
#define CHALK_UNDERLINE  "\e[4m"
#define CHALK_FLASH      "\e[5m"
#define CHALK_INVERT     "\e[7m"
#define CHALK_BLANK      "\e[8m"



// -----------------------------------------------------------------
/*
 *                    定义一些struct
 */
// -----------------------------------------------------------------
/**
 *  定义粉笔的基本属性，例如：前景色，背景色，
 *                        是否有下滑下，是否有高亮等等
 */
struct chalk {
    unsigned short forecolor; // 前景色
    unsigned short backcolor; // 背景色
    unsigned short highlight; // 高亮
    unsigned short underline; // 下划线
    unsigned short flash; // 闪烁
    unsigned short invert; // 反显
    unsigned short blank; // 消隐
    unsigned short _initialized; // 是否初始化过
    // 函数定义
    unsigned short (*setHighlight)(struct chalk *, unsigned short);
    unsigned short (*setUnderline)(struct chalk *, unsigned short);
    unsigned short (*setFlash)(struct chalk *, unsigned short);
    unsigned short (*setInvert)(struct chalk *, unsigned short);
    unsigned short (*setBlank)(struct chalk *, unsigned short);
    unsigned short (*setForecolor)(struct chalk *, char *);
    unsigned short (*setBackcolor)(struct chalk *, char *);
    unsigned short (*isInitialized)(struct chalk *);
    unsigned short (*print)(struct chalk *, char *);
};

typedef struct chalk Chalk;



// -----------------------------------------------------------------
/*
 *                     定义一些方法
 *                 可以被外界直接调用使用
 */
// -----------------------------------------------------------------
/**
 *  struct chalk数据初始化函数
 */
unsigned short initialize_chalk(struct chalk *);
#endif /* chalk_h */
