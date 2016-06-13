//
//  function_c1.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c1.h"

/**
 *  <#Description#>
 */
void getStudentInfoFromConsoleMenu()
{
    printf("\n");
    printf("\ty/Y: ");printlnInfo("确认");
    printf("\tn/N: ");printlnInfo("取消");
    printImportant("\t请选择: ");
}

/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
Student *getStudentInfoFromConsole()
{
    // 定义学生属性
    char std_id[10];
    char name[20];
    char address[50];
    int age;
    int gender;

    // 输入数据
    system("clear");
    printImportant("\t请输入学生学号: ");
    scanf("%s", std_id);
    printImportant("\t请输入学生姓名: ");
    scanf("%s", name);
    printImportant("\t请输入学生年龄: ");
    scanf("%d", &age);
    printImportant("\t请输入学生性别(1表示男性，0表示女性): ");
    scanf("%d", &gender);
    printImportant("\t请输入学生住址: ");
    scanf("%s", address);
    Student *student = createStudent(std_id, name, address, age, gender);
    
    char choose[20];
    Message *msg = createMessage(NULL, NULL);
    ushort save = FALSE;
    ushort back = FALSE;
    while (!back) {
        system("clear");
        student->printInfo(student);
        // 打印消息
        msg->printMessage(msg);
        getStudentInfoFromConsoleMenu();
        // 清空消息
        msg->setMessage(msg, "");
        scanf("%s", choose);
        switch (choose[0]) {
            case 'y':
            case 'Y':
                save = TRUE;
                back = TRUE;
                // free message
                free(msg);
                break;
            case 'n':
            case 'N':
                save = FALSE;
                back = TRUE;
                break;
            default:
                msg->setMessage(msg, "\t没有选项!");
                msg->setType(msg, "error");
                break;
        }
    }
    
    if (save) {
        return student;
    } else {
        return NULL;
    }
}

/**
 *  <#Description#>
 *
 *  @param msg <#msg description#>
 */
void printFunction1Menu(Message *msg)
{
    printf("\t-------------------------------------------\n");
    printf("\t|                                         |\n");
    printf("\t|               添加学生信息              |\n");
    printf("\t|                                         |\n");
    printf("\t-------------------------------------------\n");
    printlnImportant("\t菜单:");
    msg->printMessage(msg);
    printf("\t1: ");printlnInfo("从终端中添加用户信息");
    printf("\t2: ");printlnInfo("从文件中添加用户信息");
    printf("\t0: ");printlnInfo("返回");
    printImportant("\t请选择: ");
    msg->setMessage(msg, "");
}

ushort addStudentFromConsole(List *list)
{
    Student *student = getStudentInfoFromConsole();
    if (student != NULL) {
        return list->add(list, createNode(student));
    } else {
        return 0;
    }
}

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort addStudentFromFile(List *list)
{
    char filename[200];
    printImportant("\t请输入文件路径: ");
    scanf("%s", filename);
    return 1;
}

/**
 *  功能1 ： 添加学生信息
 *
 *  @param list 学生信息链表
 */
void function_c1(List *list)
{
    char choose[20];
    Message *msg = createMessage(NULL, NULL);
    ushort back = FALSE;
    ushort value = 0;
    while (!back) {
        system("clear");
        printFunction1Menu(msg);
        scanf("%s", choose);
        switch (choose[0]) {
            case '1':
                value = addStudentFromConsole(list);
                if (value == 0) {
                    msg->setMessage(msg, "\t学生信息添加已取消!");
                    msg->setType(msg, "warning");
                } else if(value == 1) {
                    msg->setMessage(msg, "\t学生信息添加成功!");
                    msg->setType(msg, "success");
                } else {
                    msg->setMessage(msg, "\t学生信息添加失败！该学生已经存在!");
                    msg->setType(msg, "warning");
                }
                break;
            case '2':
                addStudentFromFile(list);
                break;
            case '0':
                back = TRUE;
                //free msg
                free(msg);
                break;
            default:
                msg->setMessage(msg, "\t没有该选项!");
                msg->setType(msg, "error");
                break;
        }
    }
}