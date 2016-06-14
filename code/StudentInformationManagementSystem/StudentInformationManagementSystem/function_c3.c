//
//  function_c3.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/14.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "function_c3.h"



/**
 *  功能3：修改学生信息
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort function_c3(List *list)
{
    char identif[40];
    Message *msg = createMessage(NULL, NULL);
    while(TRUE) {
        system("clear");
        msg->printMessage(msg);
        printImportant("\t请输入学生id: ");
        msg->setMessage(msg, "");
        scanf("%s", identif);
        Node *std_node = list->search(list, identif);
        if (std_node != NULL) {
            Student *newStd = getStudentInfoFromConsole();
            if (printCompletionStudentInfo(newStd, std_node->data)) {
                // 使用新数据
                list->upd(list, std_node->data->std_id, newStd);
                return TRUE;
            } else {
                // 使用旧数据
                free(newStd);
                return FALSE;
            }
        } else {
            msg->setMessage(msg, "\t学生id不存在，请重新输入!");
            msg->setType(msg, "warning");
        }
    }
}