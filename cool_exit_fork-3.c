#include "shell.h"

/**
 * cool_fork - fork command
 * @entry: entry from keyboard
 * @cool_node: pointer
 * @_pth: path
 * @env: enviromant variables value
 *
 * Return: 0 | 1
 */
int cool_fork(char *entry, cool_instruction *cool_node, char *_pth, char **env)
{
	pid_t cool, cool_pid_child;
	char *instruction;

	if (*cool_node->instruction[0] == '/')
	{
		instruction = cool_node->instruction[0];
	}
	else
	{
		instruction = cool_find(_pth, cool_node->instruction[0]);
	}
	cool_pid_child = fork();
	if (cool_pid_child == -1)
	{
		cool_error_handl(entry, 72);
		return (0);
	}
	if (cool_pid_child == 0)
	{
		if (detail_stat(entry, instruction))
		{
			cool_execute(instruction, cool_node->instruction, env);
		}
		else
		{
			return (-1);
		}
	}
	else
	{
		wait(&cool);
	}
	return (0);
}



/**
 * cool_exit_function - exit function
 *
 * @envi: enviromental value
 */

void cool_exit_function(char **envi)
{
	(void)envi;
	exit(98);
}
