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
#include "chalk.h"

#define INFO "hello !"

int main(int argc, const char * argv[]) {
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "yellow");
    chalk->print(chalk, "hello world!\n");
    return 0;
}
