//
//  App.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/12.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef App_h
#define App_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chalk.h"
#include "list.h"
#include "message.h"
#include "function_c1.h"
#include "function_c2.h"
#include "function_c3.h"
#include "function_c4.h"
#include "function_c5.h"
#include "fucntion_c6.h"
#include "function_c7.h"

typedef unsigned short ushort;

struct app {
    void (*start)();
};

typedef struct app App;
ushort initialize_app(App *);

App *createApp();

#endif /* App_h */
