//
//  list.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "list.h"

// -------------------------------------------------------
/*
 *                  Node方法声明
 */
// -------------------------------------------------------


/**
 *  <#Description#>
 *
 *  @param data <#data description#>
 *
 *  @return <#return value description#>
 */
Node *createNode(Student *data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

// -------------------------------------------------------
/*
 *                  List方法声明
 */
// -------------------------------------------------------

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *  @param node <#node description#>
 *
 *  @return <#return value description#>
 */
ushort add_list(List *list, Node *node)
{
    if (list != NULL) {
        Node *origin = list->head;
        while(origin->next != NULL) {
            origin = origin->next;
        }
        origin->next = node;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *  @param str  <#str description#>
 *
 *  @return <#return value description#>
 */
ushort del_list(List *list, char *str)
{
    if (list != NULL) {
        Node *origin = list->head;
        while(origin->next != NULL) {
            Node *curr = origin->next;
            Student *student = curr->data;
            if (strcmp(student->std_id, str) == 0) {
                // 删除节点
                origin->next = curr->next;
                // 释放空间
                free(student);
                free(curr);
                return TRUE;
            }
            origin = origin->next;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  <#Description#>
 *
 *  @param list    <#list description#>
 *  @param str     <#str description#>
 *  @param student <#student description#>
 *
 *  @return <#return value description#>
 */
ushort upd_list(List *list, char *str, Student *student)
{
    if (list != NULL) {
        Node *origin = list->head;
        Node *newNode = createNode(student);
        while(origin->next != NULL) {
            Node *curr = origin->next;
            Student *student = curr->data;
            if (strcmp(student->std_id, str) == 0) {
                origin->next = newNode;
                newNode->next = curr->next;
                // 释放空间
                free(student);
                free(curr);
                return TRUE;
            }
            origin = origin->next;
        }
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *  @param str  <#str description#>
 *
 *  @return <#return value description#>
 */
Node *search_list(List *list, char *str)
{
    if (list != NULL) {
        Node *origin = list->head;
        while(origin->next != NULL) {
            Node *curr = origin->next;
            Student *student = curr->data;
            if (strcmp(student->std_id, str) == 0) {
                return curr;
            }
            origin = origin->next;
        }
        return NULL;
    } else {
        return NULL;
    }
}

/**
 *  <#Description#>
 *
 *  @param list <#list description#>
 *
 *  @return <#return value description#>
 */
ushort size_list(List *list)
{
    int a = 0;
    if (list != NULL) {
        Node *origin = list->head;
        while(origin->next != NULL) {
            origin = origin->next;
            a++;
        }
        return a;
    } else {
        return -1;
    }
}

/**
 *  <#Description#>
 *
 *  @param head <#head description#>
 *
 *  @return <#return value description#>
 */
List *createList(Node *head)
{
    List *tmp   = (List *)malloc(sizeof(List));
    tmp->add    = &add_list;
    tmp->del    = &del_list;
    tmp->upd    = &upd_list;
    tmp->size   = &size_list;
    tmp->search = &search_list;
    if (head != NULL) {
        tmp->head = head;
    } else {
        tmp->head = createNode(NULL);
    }
    return tmp;
}