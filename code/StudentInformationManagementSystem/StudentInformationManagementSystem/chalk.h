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

typedef unsigned short ushort;


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
    ushort forecolor; // 前景色
    ushort backcolor; // 背景色
    ushort highlight; // 高亮
    ushort underline; // 下划线
    ushort flash; // 闪烁
    ushort invert; // 反显
    ushort blank; // 消隐
    ushort _initialized; // 是否初始化过
    // 函数定义
    ushort (*setHighlight)(struct chalk *, ushort);
    ushort (*setUnderline)(struct chalk *, ushort);
    ushort (*setFlash)(struct chalk *, ushort);
    ushort (*setInvert)(struct chalk *, ushort);
    ushort (*setBlank)(struct chalk *, ushort);
    ushort (*setForecolor)(struct chalk *, char *);
    ushort (*setBackcolor)(struct chalk *, char *);
    ushort (*isInitialized)(struct chalk *);
    ushort (*print)(struct chalk *, char *);
};

typedef struct chalk Chalk;



// -----------------------------------------------------------------
/*
 *                     定义一些方法
 *                 可以被外界直接调用使用
 */
// -----------------------------------------------------------------
/**
 struct chalk数据初始化函数
 
 - returns: 初始化之后的chalk实例
 */
ushort initialize_chalk(Chalk *);

/**
 *  打印错误样式
 *
 *  @param char 错误信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printError(char *);

/**
 *  打印信息
 *
 *  @param char 基本信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printInfo(char *);

/**
 *  打印重要信息样式
 *
 *  @param char 打印重要信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printImportant(char *);
#endif /* chalk_h */
