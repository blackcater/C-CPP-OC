//
//  function_c5.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/12.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c5.h"

typedef unsigned short ushort;

/**
 *  功能5 ： 打印所有学生信息
 *
 *  @param list 学生信息链表
 */
void printAllStudentInfo(List *list)
{
    Node *origin = list->head;
    while (origin->next != NULL) {
        Node *curr = origin->next;
        Student *student = curr->data;
        student->printInfo(student);
        origin = origin->next;
    }
}

/**
 *  打印功能5 数据浏览菜单
 *
 *  @param total 总页数
 *  @param page  当前页数
 */
void printAllStudentInfoMenu(ushort total, ushort page)
{
    if (total == 0) {
        printf("\t没有数据\n");
        printf("\t-------------------------------------------\n");
        printf("\n");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    }
    if (total == 1) {
        printf("\t-------------------------------------------\n");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    }
    if (page == 1) {
        printf("\t-------------------------------------------\n");
        printf("\tt/T: ");printInfo("最后一页\t");printf("n/N: ");printlnInfo("下一页");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    } else if (page == total) {
        printf("\t-------------------------------------------\n");
        printf("\ta/A: ");printInfo("最前一页\t");printf("p/P: ");printlnInfo("前一页");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    } else {
        printf("\t-------------------------------------------\n");
        printf("\ta/A: ");printInfo("最前一页\t");printf("p/P: ");printlnInfo("前一页");
        printf("\tt/T: ");printInfo("最后一页\t");printf("n/N: ");printlnInfo("下一页");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    }
    char str[40];
    sprintf(str, "\t请选择(%d/%d): ", page, total);
    printImportant(str);
}

/**
 *  分页器
 *
 *  @param list  数据链表
 *  @param index 第几页 1开始
 *  // @param num   每页多少数据 默认为3
 *
 *  @return 指针，指向数据
 */
List *pagination(List *list, ushort index)
{
    ushort size = list->size(list);
    ushort i = 0;
    ushort num = 3;
    double total = (floor(size/3)+1);
    if (index < 1) {
        index = 0;
    } else if (index > total) {
        index = (total-1)*3;
    } else {
        index = (index-1)*3;
    }
    
    List *tmp = createList(NULL);
    Node *origin = list->head;
    while (origin->next != NULL) {
        Node *curr = origin->next;
        if (num <= 0) {
            break;
        }
        if (i >= index && num > 0) {
            num--;
            tmp->add(tmp, createNode(curr->data));
        }
        i++;
        origin = origin->next;
    }
    return tmp;
}

/**
 *  功能5 ： 浏览学生信息，支持翻页功能
 *
 *  @param list 需要的学生信息链表
 */
void function_5(List *list)
{
    char choose[10];
    ushort back  = FALSE;
    ushort size  = list->size(list);// 数据总数
    ushort total = (floor(size/3)+1);// 页数
    ushort page  = 1;// 当前页
    while (TRUE && (!back)) {
        system("clear");
        printAllStudentInfo(pagination(list, page));
        printAllStudentInfoMenu(total, page);
        scanf("%s", choose);
        switch (choose[0]) {
            case 'q':
            case 'Q':
                back = TRUE;
                break;
            case 's':
            case 'S':
                //TODO: 将结果保存在文件中
                break;
            case 'a':
            case 'A':
                page = 1;
                break;
            case 't':
            case 'T':
                page = total;
                break;
            case 'n':
            case 'N':
                if (page >= 1 && page < total) {
                    page++;
                }
                break;
            case 'p':
            case 'P':
                if (page <= total && page > 1) {
                    page--;
                }
                break;
            default:
                printError("没有选项!请重新选择!");
                usleep(100);
                break;
        }
    }
}