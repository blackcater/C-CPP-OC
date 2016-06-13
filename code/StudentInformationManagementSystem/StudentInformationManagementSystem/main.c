//
//  main.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "App.h"

int main(int argc, const char * argv[]) {
    
    App *app = createApp();
    app->start();
    
//    List *list = createList(NULL);
//    list->add(list, createNode(createStudent("20135066", "Jone", "Shenzhen,Hangzhou,China", 21, 1)));
//    list->add(list, createNode(createStudent("20135067", "Tom", "Foshan,Guangzhou,China", 22, 1)));
//    list->add(list, createNode(createStudent("20135068", "Mike", "Hubei,Xiangyang,China", 23, 1)));
//    list->add(list, createNode(createStudent("20135069", "Julia", "Shanghai,China", 24, 0)));
//    list->add(list, createNode(createStudent("20135070", "Siri", "Dalian,Liaoning,China", 25, 0)));
//    list->add(list, createNode(createStudent("20135071", "Huhu", "Shenyang,Liaoning,China", 26, 1)));
//    list->add(list, createNode(createStudent("20135072", "Xuan", "Beijing,China", 27, 1)));
//    
//    char filename[200];
//    printImportant("\t请输入文件路径: ");
//    scanf("%s", filename);
//    FILE *file = NULL;
//    file = fopen(filename, "w+");
//    
//    if (file != NULL) {
//        Node *head = list->head;
//        
//        while (head->next != NULL) {
//            Node *curr = head->next;
//            Student *student = curr->data;
//            fprintf(file, "%s\t%s\t%d\t%d\t%s\n", student->std_id, student->name, student->age, student->gender, student->address);
//            head = head->next;
//        }
//        
//        fclose(file);
//    } else {
//        printError("文件打开失败!");
//    }
    
    return 0;
}
