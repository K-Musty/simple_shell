#include "shell.h"
#include <stdio.h>

/**
 * cool_prompt - collects instruction from keyboard
 * @entry: all things entered by keyboard
 * @cool_arg: arguments
 *
 * Return: NULL or pointer to command list.
 */
cool_instruction **cool_prompt(char *entry, char *cool_arg)
{
	cool_instruction *cool_node = NULL;
	size_t buffer = 0;
	ssize_t charact = 0;
	char *term = NULL;
	cool_instruction **cool_term = &cool_node;

	if (isatty(STDIN_FILENO))
	{
		charact = getline(&term, &buffer, stdin);
	}
	else
	{
		term = cool_arg;
	}
	fflush(stdin);

	if (charact < 0)
		cool_term = NULL;
	else
	{
		*cool_term = cool_space_parser(entry, term);
		free(term);
		term = NULL;
		return (cool_term);
	}
	return (NULL);
}

/**
 * cool_space_parser - Spaces of all entries from the prompt is parsed
 * @term: terminal writing
 * @entry: all things entered by and from keyboard (command)
 *
 * Return: Null
 */
cool_instruction *cool_space_parser(char *term, char *entry)
{
	const char *cool_argv = " \n";
	char *cool_string = NULL;
	size_t k = 0;
	cool_instruction *cool_node = NULL;

	cool_string = strtok(term, cool_argv);
	if (cool_string)
	{
		cool_node = cool_get_term(entry);
		cool_token(entry, cool_node, k, cool_string);
		while (cool_string != NULL)
		{
			cool_string == NULL ? k : k++;
			cool_string = strtok(NULL,cool_argv);
			if (cool_string)
				cool_token(entry, cool_node, k, cool_string);
		}
	}
	return (cool_node);
}

/**
 * cool_in_line - reads the entries from keyboard
 *
 * Return: NULL
 */
char *cool_in_line(void)
{
	size_t loader = 0;
	char *cool_line = NULL;

	getline(&cool_line, &loader, stdin);
	return (cool_line);
}

/**
 * cool_execute - this function shows execve usage
 * @instruction: instruction to be executed
 * @instruct: instruction
 * @env: enviroment
 *
 * Return: 0
 */
int cool_execute(char *instruction, char **instruct, char **env)
{
	if (execve(instruction, instruct, env) == -1)
	{
		perror("Error:");
		return (-1);
	}
	else
	{
		return (0);
	}
}


/**
 * detail_ - details of given file
 * @entry: entry point
 * @instruct: the instruction
 *
 * Return: 1 or 0
 */
int detail_stat(char *entry, char *instruct)
{
	struct stat det;

	if (stat(instruct, &det) == 0)
		return (1);
	cool_error_handl(entry, 73);
	return (0);
}
