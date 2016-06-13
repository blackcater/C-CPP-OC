//
//  chalk.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//
#include "chalk.h"

/**
 *  将字符串颜色与结果进行对应
 *
 *  @param color       需要进行颜色映射的颜色名称
 *  @param isForeColor 是否为前景色
 *
 *  @return 返回结果值
 */
ushort mapColorToResult(char *color,
                        ushort isForeColor)
{
    if (strcmp(color, "black") == 0) {
        return (30 + (isForeColor?0:10));
    }
    if (strcmp(color, "red") == 0) {
        return (31 + (isForeColor?0:10));
    }
    if (strcmp(color, "green") == 0) {
        return (32 + (isForeColor?0:10));
    }
    if (strcmp(color, "yellow") == 0) {
        return (33 + (isForeColor?0:10));
    }
    if (strcmp(color, "blue") == 0) {
        return (34 + (isForeColor?0:10));
    }
    if (strcmp(color, "pink") == 0) {
        return (35 + (isForeColor?0:10));
    }
    if (strcmp(color, "darkgreen") == 0) {
        return (36 + (isForeColor?0:10));
    }
    if (strcmp(color, "white") == 0) {
        return (37 + (isForeColor?0:10));
    }
    return 0;
}

/**
 *  判断chalk实例是否被初始化
 *
 *  @param chalk 需要进行判断的chalk实例
 *
 *  @return 如果已经被初始化，则返回1，否则返回0
 */
ushort isInitialized_chalk(Chalk *chalk)
{
    if (chalk != NULL) {
        return (chalk->_initialized == 1)?TRUE:FALSE;
    } else {
        return FALSE;
    }
}

/**
 *  设置是否高亮显示
 *
 *  @param chalk     需要进行高亮设置的chalk实例
 *  @param highlight 1表示设置高亮，0表示取消高亮设置
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setHighlight_chalk(Chalk *chalk,
                          ushort highlight)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->highlight = highlight;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置是否显示下滑线
 *
 *  @param chalk     需要进行下划线设置的chalk实例
 *  @param underline 1表示设置下划线，0表示取消下划线设置
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setUnderline_chalk(Chalk *chalk,
                          ushort underline)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->underline = underline;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置是否闪烁显示
 *
 *  @param chalk 需要进行闪烁显示设置的chalk实例
 *  @param flash 1表示闪烁显示设置成功，0表示取消闪烁显示设置
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setFlash_chalk(Chalk *chalk,
                      ushort flash)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->flash = flash;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置反显效果
 *
 *  @param chalk  需要进行反显设置的chalk实例
 *  @param invert 1表示设置反显效果，0表示取消反显效果
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setInvert_chalk(Chalk *chalk,
                       ushort invert)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->invert = invert;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置消隐效果
 *
 *  @param chalk  需要进行消隐设置的chalk实例
 *  @param invert 1表示设置消隐效果，0表示取消消隐效果
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setBlank_chalk(Chalk *chalk,
                      ushort blank)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->blank = blank;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置前景色
 *
 *  @param chalk 需要进行前景色设置的chalk实例
 *  @param color 前景色颜色名称
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setForecolor_chalk(Chalk *chalk,
                          char* color)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->forecolor = mapColorToResult(color, 1);
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  设置背景色
 *
 *  @param chalk 需要进行背景色设置的chalk实例
 *  @param color 背景色颜色名称
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort setBackcolor_chalk(Chalk *chalk,
                          char* color)
{
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        chalk->backcolor = mapColorToResult(color, 0);
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  打印彩色结果
 *
 *  @param chalk   需要的chalk实例
 *  @param message 需要彩色输出的信息
 *
 *  @return 1表示操作成功，0表示操作失败
 */
ushort print_chalk(Chalk *chalk,
                   char *message,
                   ushort newline)
{
    char res[512]      = "";
    char forecolor[20] = "";
    char backcolor[20] = "";
    char highlight[20] = "";
    char underline[20] = "";
    char flash[20]     = "";
    char invert[20]    = "";
    char blank[20]     = "";
    if (chalk != NULL && chalk->isInitialized(chalk)) {
        if (chalk->forecolor != 0) {
            sprintf(forecolor, CHALK_START "%d" CHALK_END, chalk->forecolor);
        }
        if (chalk->backcolor != 0) {
            sprintf(backcolor, CHALK_START "%d" CHALK_END, chalk->backcolor);
        }
        if (chalk->highlight == 1) {
            sprintf(highlight, CHALK_HIGHLIGHT);
        }
        if (chalk->underline == 1) {
            sprintf(underline, CHALK_UNDERLINE);
        }
        if (chalk->flash == 1) {
            sprintf(flash, CHALK_FLASH);
        }
        if (chalk->invert == 1) {
            sprintf(invert, CHALK_INVERT);
        }
        if (chalk->blank == 1) {
            sprintf(blank, CHALK_BLANK);
        }
        strcat(res, forecolor);
        strcat(res, backcolor);
        strcat(res, highlight);
        strcat(res, underline);
        strcat(res, flash);
        strcat(res, invert);
        strcat(res, blank);
        strcat(res, message);
        strcat(res, CHALK_ATTR_CLOSE);
        if (newline) {
            strcat(res, "\n");
        } else {
            strcat(res, "");
        }
        printf("%s" , res);
        return TRUE;
    } else {
        return FALSE;
    }
}


/**
 *      用于struct chalk的数据初始化操作
 *
 *  @params:
 - returns: void
 */
ushort initialize_chalk(Chalk *chalk)
{
    if ((chalk != NULL) && (chalk->_initialized != 1)) {
        // 不为空指针，且未被初始化
        chalk->forecolor     = 0; // 默认系统前景色
        chalk->backcolor     = 0; // 默认系统背景色
        chalk->highlight     = 0;
        chalk->underline     = 0;
        chalk->flash         = 0;
        chalk->invert        = 0;
        chalk->blank         = 0;
        chalk->_initialized  = 1;
        // 函数指针初始化
        chalk->isInitialized = &isInitialized_chalk;
        chalk->setHighlight  = &setHighlight_chalk;
        chalk->setUnderline  = &setUnderline_chalk;
        chalk->setFlash      = &setFlash_chalk;
        chalk->setInvert     = &setInvert_chalk;
        chalk->setBlank      = &setBlank_chalk;
        chalk->setForecolor  = &setForecolor_chalk;
        chalk->setBackcolor  = &setBackcolor_chalk;
        chalk->print         = &print_chalk;
        return TRUE;
    } else {
        // 输出错误信息
        fprintf(stderr, "Error : Chalk could be initialized!");
        return FALSE;
    }
}

/**
 *  打印错误样式
 *
 *  @param char 错误信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printError(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "red");
    chalk->setHighlight(chalk, 1);
    chalk->setInvert(chalk, 1);
    return chalk->print(chalk, message, 0);
}

/**
 *  打印错误样式
 *
 *  @param char 错误信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printlnError(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "red");
    chalk->setHighlight(chalk, 1);
    chalk->setInvert(chalk, 1);
    return chalk->print(chalk, message, 1);
}


/**
 *  打印信息
 *
 *  @param char 基本信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printInfo(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "green");
    chalk->setUnderline(chalk, 1);
    return chalk->print(chalk, message, 0);
}

/**
 *  打印信息
 *
 *  @param char 基本信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printlnInfo(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "green");
    chalk->setUnderline(chalk, 1);
    return chalk->print(chalk, message, 1);
}


/**
 *  打印重要信息样式
 *
 *  @param char 打印重要信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printImportant(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "darkgreen");
    chalk->setHighlight(chalk, 1);
    return chalk->print(chalk, message, 0);
}

/**
 *  打印重要信息样式
 *
 *  @param char 打印重要信息
 *
 *  @return 1表示成功，0表示失败
 */
ushort printlnImportant(char *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "darkgreen");
    chalk->setHighlight(chalk, 1);
    return chalk->print(chalk, message, 1);
}