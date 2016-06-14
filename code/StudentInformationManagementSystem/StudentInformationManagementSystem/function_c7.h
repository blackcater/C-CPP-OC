//
//  function_c7.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef function_c7_h
#define function_c7_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "chalk.h"
#include "list.h"
#include "message.h"

ushort function_c7(List *);

ushort saveStudentInfoToFile(List *list, FILE *file);

#endif /* function_c7_h */
