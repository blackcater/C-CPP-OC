//
//  App.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/12.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "App.h"

void printSysInfo()
{
    printf("\t-------------------------------------------\n");
    printf("\t|                                         |\n");
    printf("\t|            学生信息管理系统             |\n");
    printf("\t|                                         |\n");
    printf("\t-------------------------------------------\n");
}

void printSysMenu()
{
    printlnImportant("\t菜单:");
    printf("\t1: ");printlnInfo("添加学生信息");
    printf("\t2: ");printlnInfo("删除学生信息");
    printf("\t3: ");printlnInfo("修改学生信息");
    printf("\t4: ");printlnInfo("查看学生信息");
    printf("\t5: ");printlnInfo("浏览学生信息");
    printf("\t6: ");printlnInfo("导入学生信息");
    printf("\t7: ");printlnInfo("导出学生信息");
    printf("\t0: ");printlnInfo("Exit");
    printImportant("\t请选择: ");
}



void init(Message *msg)
{
    printSysInfo();
    msg->printMessage(msg);
    printSysMenu();
}
#if 0
List *initData()
{
    List *tmp = createList(NULL);
//    20135066	Jone	21	1	Shenzhen,Hangzhou,China
//    20135067	Tom	22	1	Foshan,Guangzhou,China
//    20135068	Mike	23	1	Hubei,Xiangyang,China
//    20135069	Julia	24	0	Shanghai,China
//    20135070	Siri	25	0	Dalian,Liaoning,China
//    20135071	Huhu	26	1	Shenyang,Liaoning,China
//    20135072	Xuan	27	1	Beijing,China
    tmp->add(tmp, createNode(createStudent("20135066", "Jone", "Shenzhen,Hangzhou,China", 21, 1)));
    tmp->add(tmp, createNode(createStudent("20135067", "Tom", "Foshan,Guangzhou,China", 22, 1)));
    tmp->add(tmp, createNode(createStudent("20135068", "Mike", "Hubei,Xiangyang,China", 23, 1)));
    tmp->add(tmp, createNode(createStudent("20135069", "Julia", "Shanghai,China", 24, 0)));
    tmp->add(tmp, createNode(createStudent("20135070", "Siri", "Dalian,Liaoning,China", 25, 0)));
    tmp->add(tmp, createNode(createStudent("20135071", "Huhu", "Shenyang,Liaoning,China", 26, 1)));
    tmp->add(tmp, createNode(createStudent("20135072", "Xuan", "Beijing,China", 27, 1)));
    return tmp;
}
#endif

void start()
{
//    List *list = initData();
    List *list = createList(NULL);
    Message *msg = createMessage(NULL, NULL);
    char choose[10];
    while (TRUE) {
        system("clear");
        // 初始化输出
        init(msg);
        // 清空历史错误信息
        msg->setMessage(msg, "");
        scanf("%s", choose);
        switch (choose[0]) {
            case '0':
                exit(0);
                break;
            case '1':
                function_c1(list);
                break;
            case '2':
                if (function_c2(list)) {
                    msg->setMessage(msg, "\t学生删除成功!");
                    msg->setType(msg, "success");
                } else {
                    msg->setMessage(msg, "\t学生删除失败!");
                    msg->setType(msg, "error");
                }
                break;
            case '3':
                if (function_c3(list)) {
                    msg->setMessage(msg, "\t学生修改成功!");
                    msg->setType(msg, "success");
                } else {
                    msg->setMessage(msg, "\t学生修改取消!");
                    msg->setType(msg, "warning");
                }
                break;
            case '4':
                function_c4(list);
                break;
            case '5':
                function_c5(list);
                break;
            case '6':
                function_c6(list);
                break;
            case '7':
                if (function_c7(list)) {
                    msg->setMessage(msg, "\t学生信息导出成功!");
                    msg->setType(msg, "success");
                } else {
                    msg->setMessage(msg, "\t学生信息导出失败!");
                    msg->setType(msg, "error");
                }
                break;
            default:
                msg->setMessage(msg, "\t输入必须在(0-7)之间的整数!");
                msg->setType(msg, "error");
                break;
        }
    }
}


/**
 <#Description#>
 
 - returns: 1表示初始化成功，0表示初始化失败
 */
ushort initialize_app(App *app)
{
    if (app != NULL) {
        app->start = &start;
        return TRUE;
    }
    return FALSE;
}

App *createApp()
{
    App *tmp = (App *)malloc(sizeof(App));
    initialize_app(tmp);
    return tmp;
}