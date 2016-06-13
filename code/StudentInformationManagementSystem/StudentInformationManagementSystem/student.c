//
//  student.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "student.h"

/**
 *  对学生进行比较，实际比较的是他们的std_id属性
 *
 *  @param student  学生实例1
 *  @param bstudent 学生实例2
 *
 *  @return 0表示相等，1表示student > bstudent, -1表示student < bstudent, -2表示出错
 */
short equal(Student *student, Student *bstudent)
{
    if (student!=NULL && bstudent!=NULL) {
        return strcmp(student->std_id, bstudent->std_id);
    } else {
        return -2;
    }
}

/**
 *  打印学生的信息
 *
 *  @param student 需要打印信息的学生
 */
void printInfo_student(Student *student)
{
    if (student != NULL) {
        char gender[8] = "";
        if (student->gender) {
            strcpy(gender, "male");
        } else {
            strcpy(gender, "female");
        }
        printlnInfo("\t-------------------------------------------");
        printImportant("\tStuden_id:\t"); printf("%s\n", student->std_id);
        printImportant("\tName:\t\t"); printf("%s\n", student->name);
        printImportant("\tAge:\t\t"); printf("%d\n", student->age);
        printImportant("\tGender:\t\t"); printf("%s\n", gender);
        printImportant("\tAddress:\t"); printf("%s\n", student->address);
    }
}

/**
 初始化学生
 
 - returns: TRUE表示成功，FALSE表示失败
 */
ushort initialize_student(Student *student,
                          char *std_id,
                          char *name,
                          char *address,
                          ushort age,
                          ushort gender)
{
    if (student != NULL) {
        strcpy(student->std_id, std_id);
        strcpy(student->name, name);
        strcpy(student->address, address);
        student->age = age;
        student->gender = gender;
        student->euqal = &equal;
        student->printInfo = &printInfo_student;
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 *  创建一个学生
 *
 *  @param std_id  学生id
 *  @param name    学生姓名
 *  @param address 学生住址
 *  @param age     学生年龄
 *  @param gender  学生性别，1表示male 0表示female
 *
 *  @return 学生指针
 */
Student * createStudent(char *std_id,
                        char *name,
                        char *address,
                        ushort age,
                        ushort gender)
{
    Student *tmp = (Student *)malloc(sizeof(Student));
    if (initialize_student(tmp, std_id, name, address, age, gender)) {
        return tmp;
    } else {
        return NULL;
    }
}

/**
 *  释放学生信息空间
 *
 *  @param student 学生指针
 *
 *  @return 1表示释放成功
 */
ushort free_student(Student *student)
{
    free(student);
    return 1;
}