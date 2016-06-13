//
//  message.c
//  StudentInformationManagementSystem
//
//  Created by blackcater on 16/6/13.
//  Copyright © 2016年 blackcater. All rights reserved.
//

#include "message.h"

/**
 *  <#Description#>
 *
 *  @param error   <#error description#>
 *  @param message <#message description#>
 */
void setMessage_msg(Message *message, char *msg)
{
    strcpy(message->str, msg);
}

/**
 *  <#Description#>
 *
 *  @param error   <#error description#>
 *  @param message <#message description#>
 */
void setType_msg(Message *message, char *type)
{
    strcpy(message->type, type);
}


/**
 *  <#Description#>
 *
 *  @param message <#message description#>
 *
 *  @return <#return value description#>
 */
ushort printError_msg(Message *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "red");
    chalk->setHighlight(chalk, 1);
    chalk->setInvert(chalk, 1);
    return chalk->print(chalk, message->str, 1);
}

/**
 *  <#Description#>
 *
 *  @param messgae <#messgae description#>
 *
 *  @return <#return value description#>
 */
ushort printWarning_msg(Message *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "yellow");
    chalk->setHighlight(chalk, 1);
    chalk->setInvert(chalk, 1);
    return chalk->print(chalk, message->str, 1);
}

ushort printSuccess_msg(Message *message)
{
    Chalk *chalk = (Chalk *)malloc(sizeof(Chalk));
    initialize_chalk(chalk);
    chalk->setForecolor(chalk, "darkgreen");
    chalk->setHighlight(chalk, 1);
    chalk->setInvert(chalk, 1);
    return chalk->print(chalk, message->str, 1);
}

/**
 *  <#Description#>
 *
 *  @param message <#message description#>
 *  @param type    <#type description#>
 *
 *  @return <#return value description#>
 */
ushort printMessage_msg(Message *message)
{
    if ((message->type) != NULL) {
        if (strcmp(message->type, "success") == 0) {
            return message->printSuccess(message);
        } else if(strcmp(message->type, "error") == 0) {
            return message->printError(message);
        } else if(strcmp(message->type, "warning") == 0) {
            return message->printWarning(message);
        }
        return message->printSuccess(message);

    } else{
        return message->printSuccess(message);
    }
}

/**
 *  <#Description#>
 *
 *  @param message <#message description#>
 *
 *  @return <#return value description#>
 */
Message *createMessage(char *msg, char *type)
{
    Message *message = (Message *)malloc(sizeof(Message));
    if (msg != NULL) {
        strcpy(message->str, msg);
    } else {
        strcpy(message->str, "");
    }
    if (type != NULL) {
        strcpy(message->type, type);
    } else {
        strcpy(message->type, "success");
    }
    message->setMessage   = &setMessage_msg;
    message->setType      = &setType_msg;
    message->printError   = &printError_msg;
    message->printWarning = &printWarning_msg;
    message->printSuccess = &printSuccess_msg;
    message->printMessage = &printMessage_msg;
    return message;
}