//
//  list.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

typedef unsigned short ushort;

struct node {
    Student *data;
    struct node *next;
};

struct list {
    struct node *head;
    ushort (*add)(struct list *, struct node *);
    ushort (*del)(struct list *, char *);
    ushort (*upd)(struct list *, char *, Student *);
    ushort (*size)(struct list *);
    struct node *(*search)(struct list *, char *);
};

typedef struct node Node;
typedef struct list List;

Node *createNode(Student *);

ushort free_node(Node *);

List *createList(Node *);

ushort free_list(List *);

#endif /* list_h */
