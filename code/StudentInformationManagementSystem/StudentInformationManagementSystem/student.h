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

struct student {
    char *std_id;
    char *name;
    char *address;
    unsigned short age;
    unsigned short gender;
};

typedef struct student Student;



#endif /* student_h */
