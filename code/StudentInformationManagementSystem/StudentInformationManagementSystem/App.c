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



void init()
{
    printSysInfo();
    printSysMenu();
}

List *initData()
{
    List *list = createList(NULL);
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 21, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 22, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 23, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 24, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 25, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 26, 1)));
    list->add(list, createNode(createStudent("20135066", "Tom Tang", "Hubei, Xiangyang, China", 27, 1)));
    return list;
}

void start()
{
    List *list = initData();
    char choose[10];
    while (TRUE) {
        system("clear");
        init();
        scanf("%s", choose);
        switch (choose[0]) {
            case '0':
                exit(0);
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                function_5(list);
                break;
            case '6':
                break;
            case '7':
                break;
            default:
                printlnError("输入必须在(0-7)之间的整数!");
                usleep(100);
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