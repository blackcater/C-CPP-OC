//
//  message.h
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#ifndef message_h
#define message_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chalk.h"

struct message {
    char str[100];
    char type[10];
    void (*setMessage)(struct message *, char *);
    void (*setType)(struct message *, char *);
    ushort (*printError)(struct message *);
    ushort (*printWarning)(struct message *);
    ushort (*printSuccess)(struct message *);
    ushort (*printMessage)(struct message *);
};

typedef struct message Message;

/**
 *  <#Description#>
 *
 *  @param char <#char description#>
 *
 *  @return <#return value description#>
 */
Message *createMessage(char *, char *);

#endif /* message_h */
