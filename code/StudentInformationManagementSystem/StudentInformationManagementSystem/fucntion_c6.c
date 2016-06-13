//
//  fucntion_c6.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "fucntion_c6.h"

List *getListFromFile(FILE *file)
{
    List *tmp = createList(NULL);
    while (!feof(file)) {
        char std_id[10];
        char name[20];
        char address[50];
        int age;
        int gender;
        fscanf(file, "%s\t%s\t%d\t%d\t%s\n", std_id, name, &age, &gender, address);
        Student *std = createStudent(std_id, name, address, age, gender);
        tmp->add(tmp, createNode(std));
    }
    fclose(file);
    return tmp;
}


/**
 *  功能6：导入学生信息
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort function_c6(List *list)
{
    char filename[200];
    Message *msg = createMessage(NULL, NULL);
    ushort back = FALSE;
    while (!back) {
        system("clear");
        msg->printMessage(msg);
        printImportant("\t请输入数据文件路径: ");
        scanf("%s", filename);
        
        // 打开文件
        FILE *file = fopen(filename, "r");
        if (file != NULL) {
            
            List *tmpList = getListFromFile(file);
            // TODO: 将学生信息导入其中，可能出现同std_id情况，予以解决。
        } else {
            msg->setMessage(msg, "\t数据文件不存在!");
            msg->setType(msg, "warning");
        }
    }
    
    
    
    
    return TRUE;
}