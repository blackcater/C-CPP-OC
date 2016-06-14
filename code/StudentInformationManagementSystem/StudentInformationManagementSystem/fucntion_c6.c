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

void printTwoStudentInfo(Student *newStd, Student *oldStd, Message *msg)
{
    printlnImportant("\t新 学生信息: ");
    newStd->printInfo(newStd);
    printlnInfo("");
    printlnImportant("\t旧 学生信息: ");
    oldStd->printInfo(oldStd);
    printlnInfo("");
    msg->printMessage(msg);
    printf("\tn/N: ");printlnInfo("使用新 学生信息");
    printf("\to/O: ");printlnInfo("使用旧 学生信息");
    msg->setMessage(msg, "");
    printImportant("\t请选择: ");
}

/**
 *  <#Description#>
 *
 *  @param newStd <#newStd description#>
 *  @param oldStd <#oldStd description#>
 *
 *  @return 1表示使用新版本数据，0表示使用旧版本数据
 */
ushort printCompletionStudentInfo(Student *newStd, Student *oldStd)
{
    
    char choose[20];
    Message *msg = createMessage(NULL, NULL);
    while (TRUE) {
        system("clear");
        printTwoStudentInfo(newStd, oldStd, msg);
        scanf("%s", choose);
        switch (choose[0]) {
            case 'n':
            case 'N':
                return TRUE;
                break;
            case 'o':
            case 'O':
                return FALSE;
                break;
            default:
                msg->setMessage(msg, "\t没有选项!");
                msg->setType(msg, "error");
                break;
        }
    }
}


/**
 *  将数据添加到链表中
 *
 *  @param tmpList 将要添加到链表中的数据
 *  @param list    数据列表
 */
void addStudentToMainList(List *tmpList, List *list)
{
    Node *origin = tmpList->head;
    while (origin->next != NULL) {
        Node *curr = createNode(origin->next->data);
        if (list->contain(list, curr->data->std_id)) {
            // 学生信息冲突，用户进行选择
            Node *oldNode = list->search(list, curr->data->std_id);

            if (printCompletionStudentInfo(curr->data, oldNode->data)) {
                // 使用新版本数据
                list->upd(list, curr->data->std_id, curr->data);
            }
        } else {
            list->add(list, curr);
        }
        origin = origin->next;
    }
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
            // 遍历文件中多有的学生信息
            addStudentToMainList(tmpList, list);
            return TRUE;
        } else {
            msg->setMessage(msg, "\t数据文件不存在!");
            msg->setType(msg, "warning");
        }
    }
    
    return TRUE;
}