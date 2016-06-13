//
//  function_c2.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c2.h"

void getStdIdFromConsole(char *std_id)
{
    printImportant("\t请输入您要查找的学生ID: ");
    scanf("%s", std_id);
}

void whetherDeleteStudentMenu()
{
    printf("\n");
    printf("\ty/Y: ");printlnInfo("删除");
    printf("\tn/N: ");printlnInfo("取消");
    printImportant("\t请选择: ");
}

ushort whetherDeleteStudent(Student *student)
{
    char choose[20];
    Message *msg = createMessage(NULL, NULL);
    while (TRUE) {
        system("clear");
        student->printInfo(student);
        msg->printMessage(msg);
        whetherDeleteStudentMenu();
        msg->setMessage(msg, "");
        scanf("%s", choose);
        switch (choose[0]) {
            case 'y':
            case 'Y':
                return 1;
                break;
            case 'n':
            case 'N':
                return 0;
                break;
            default:
                msg->setMessage(msg, "\t没有选项! ");
                msg->setType(msg, "error");
                break;
        }
    }
}

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort function_c2(List *list)
{
    char stdid[10];
    Message *msg = createMessage(NULL, NULL);
    ushort back = FALSE;
    ushort returnValue = 0;
    while (!back) {
        system("clear");
        msg->printMessage(msg);
        getStdIdFromConsole(stdid);
        msg->setMessage(msg, "");
        
        Node *node = list->search(list, stdid);
        // 没有查询到学生信息
        if (node == NULL) {
            msg->setMessage(msg, "\t学生不存在!");
            msg->setType(msg, "warning");
            continue;
        }
        // 查询到学生信息
        Student *student = node->data;
        if (whetherDeleteStudent(student)) {
            back = TRUE;
            returnValue = list->del(list, student->std_id);
        } else {
            msg->setMessage(msg, "\t已取消学生删除! ");
            msg->setType(msg, "warning");
        }
    }
    return returnValue;
}