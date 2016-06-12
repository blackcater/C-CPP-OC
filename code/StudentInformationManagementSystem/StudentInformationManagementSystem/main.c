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
    return 0;
}
