#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_ARGUMENTS 50
/**
 * cool_command - command struct reciever
 *@command_name: command name pointer
 *@cool_arg: argument poointer
 */
typedef struct {
    char *command_name;
    char *cool_arg[MAX_ARGUMENTS];
    // Add more fields for redirection info, flags, etc. if needed
} cool_command;




#endif 
