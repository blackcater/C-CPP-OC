//
//  function_c4.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/14.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c4.h"

void saveStdInfoToFile(Student *std)
{
    char filename[200];
    Message *msg = createMessage(NULL, NULL);
    ushort back = FALSE;
    while (!back) {
        system("clear");
        msg->printMessage(msg);
        printImportant("\t请输入保存文件路径: ");
        scanf("%s", filename);
        
        // 打开文件
        FILE *file = fopen(filename, "w+");
        if (file != NULL) {
            // 写入数据
            fprintf(file, "%s\t%s\t%d\t%d\t%s\n", std->std_id, std->name, std->age, std->gender, std->address);
            fclose(file);
            return ;
        } else {
            msg->setMessage(msg, "\t数据文件不存在,或者你无权访问该路径!");
            msg->setType(msg, "warning");
        }
    }
}

void printStdInfoMenu()
{
    printlnInfo("");
    printf("\tb/B: ");printlnImportant("返回");
    printf("\ts/S: ");printlnImportant("保存");
    printImportant("\t请选择: ");
}

void printStdInfo(Student *std)
{
    char choose[20];
    Message *msg = createMessage(NULL, NULL);
    while (TRUE) {
        system("clear");
        msg->printMessage(msg);
        std->printInfo(std);
        printStdInfoMenu();
        msg->setMessage(msg, "");
        scanf("%s", choose);
        switch (choose[0]) {
            case 'b':
            case 'B':
                return;
            case 's':
            case 'S':
                saveStdInfoToFile(std);
                return;
            default:
                msg->setMessage(msg, "\t没有改选项!");
                msg->setType(msg, "warning");
                break;
        }
    }
}

void function_c4(List *list)
{
    char identif[40];
    Message *msg = createMessage(NULL, NULL);
    while(TRUE) {
        system("clear");
        msg->printMessage(msg);
        printImportant("\t请输入学生id: ");
        msg->setMessage(msg, "");
        scanf("%s", identif);
        if (identif[0] == 'q' || identif[0] == 'Q') {
            return ;
        }
        Node *std_node = list->search(list, identif);
        if (std_node != NULL) {
            Student *std = std_node->data;
            printStdInfo(std);
            return ;
        } else {
            msg->setMessage(msg, "\t学生id不存在，请重新输入!");
            msg->setType(msg, "warning");
        }
    }
}