#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct cool_command_
{
	char **command;
	struct cool_command_ *next;
} cool_command;


#endif
