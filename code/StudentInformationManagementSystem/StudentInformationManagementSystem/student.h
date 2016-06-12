//
//  student.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/11.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chalk.h"

typedef unsigned short ushort;

struct student {
    char std_id[10];
    char name[20];
    char address[50];
    ushort age;
    ushort gender;
    void (*printInfo)(struct student *);
    short (*euqal)(struct student *, struct student *);
};

typedef struct student Student;


ushort initialize_student(Student *,
                          char *,
                          char *,
                          char *,
                          ushort ,
                          ushort);

Student * createStudent(char *std_id,
                        char *name,
                        char *address,
                        ushort age,
                        ushort gender);


#endif /* student_h */
