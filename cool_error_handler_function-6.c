#include "shell.h"
/**
 * cool_error_handl - This function handles unfortunate errors
 * @entry: Entry from the keyboard
 * @cool_message: number error
 */
void cool_error_handl(char *entry, int cool_message)
{
	char *cool_error = NULL;

	switch (cool_message)
	{
		case 70:
			cool_error = "Error unknown\n";
			break;
		case 71:
			cool_error = "Error from Prompt - Zero tokens\n";
			break;
		case 72:
			cool_error = "No such file or directory\n";
			break;
		case 74:
			cool_error = "FATAL ERROR: UNABLE TO CREATE CHILD PROCESS\n";
			break;
		case 75:
			cool_error = "command not found\n";
			break;
		case 73:
			cool_error = "FATAL ERROR: NO MEMORY AVAILABLE\n";
			break;
		case 76:
			cool_error = "FATAL ERROR: UNABLE TO CREATE CMD LIST\n";
			break;
	}

	write(STDERR_FILENO, entry, strlength(entry));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cool_error, strlength(cool_error));
}

/**
 * cool_free_list -  frees list
 * @top: pointer
 */
void cool_free_list(record_ *top)
{
	record_ *clear;

	if (!top)
		return;
	while (top)
	{
		clear = top->nxt;
		free(top->rec);
		free(top->prv);
		free(top);
		top = clear;
	}
	free(clear);
}

/**
 * cool_print_list - Print list
 * @pointer: The pointer
 *
 * Return: The number of elements in the list
 */

void cool_print_list(const record_ *pointer)
{
	while (pointer)
	{
		printf(":Debugg record :%s\n", pointer->rec);
		pointer = pointer->nxt;
	}
}
