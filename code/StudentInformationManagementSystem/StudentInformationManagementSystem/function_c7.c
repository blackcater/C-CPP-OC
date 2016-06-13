//
//  function_c7.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c7.h"

/**
 *  将list中数据保存到文件中
 *
 *  @param list <#list description#>
 *  @param file <#file description#>
 *
 *  @return <#return value description#>
 */
ushort saveStudentInfoToFile(List *list, FILE *file)
{
    if (list != NULL) {
        Node *origin = list->head;
        while (origin->next != NULL) {
            Node *curr = origin->next;
            Student *std = curr->data;
            fprintf(file, "%s\t%s\t%d\t%d\t%s\n", std->std_id, std->name, std->age, std->gender, std->address);
            origin = origin->next;
        }
        fclose(file);
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  功能7：导出学生信息
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort function_c7(List *list)
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
            if (saveStudentInfoToFile(list, file)) {
                back = TRUE;
            } else {
                msg->setMessage(msg, "\t写入文件失败!");
                msg->setType(msg, "error");
                return 0;
            };
        } else {
            msg->setMessage(msg, "\t数据文件不存在,或者你无权访问该路径!");
            msg->setType(msg, "warning");
        }
    }
    return 1;
}