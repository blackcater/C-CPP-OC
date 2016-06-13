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
void printAllStudentInfoMenu(ushort total, ushort page, ushort size)
{
    if (size == 0) {
        printf("\t没有数据\n");
        printf("\t-------------------------------------------\n");
        printf("\n");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    } else if (total == 1) {
        printf("\t-------------------------------------------\n");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    } else if (page == 1 && total >= 2) {
        printf("\t-------------------------------------------\n");
        printf("\tt/T: ");printInfo("最后一页\t");printf("n/N: ");printlnInfo("下一页");
        printf("\ts/S: ");printlnInfo("保存结果");
        printf("\tq/Q: ");printlnInfo("返回菜单页面");
    } else if (page == total && total >= 2) {
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
    if (size != 0) {
        sprintf(str, "\t请选择(%d/%d): ", page, total);
    } else {
        sprintf(str, "\t请选择: ");
    }
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
void function_c5(List *list)
{
    char choose[10];
    ushort back  = FALSE;
    ushort size  = list->size(list);// 数据总数
    ushort total = (floor(size/3)+1);// 页数
    ushort page  = 1;// 当前页
    Message *msg = createMessage(NULL, NULL);
    while (TRUE && (!back)) {
        system("clear");
        printAllStudentInfo(pagination(list, page));
        // 打印信息
        msg->printMessage(msg);
        printAllStudentInfoMenu(total, page, size);
        // 清空信息
        msg->setMessage(msg, "");
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
                } else {
                    msg->setMessage(msg, "\t已经是最后一页，没有更多的数据!");
                    msg->setType(msg, "warning");
                }
                break;
            case 'p':
            case 'P':
                if (page <= total && page > 1) {
                    page--;
                } else {
                    msg->setMessage(msg, "\t已经是第一页,没有更多的数据!");
                    msg->setType(msg, "warning");
                }
                break;
            default:
                msg->setMessage(msg, "\t没有选项!请重新选择!");
                msg->setType(msg, "error");
                break;
        }
    }
}