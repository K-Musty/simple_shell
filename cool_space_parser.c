#include "shell.h"
/**
 * cool_space_parser - Parses a simple command from prompt.
 * @myself: my own name as shell.
 * @cmd_line: command line to be parsed from prompt.
 *
 * Return: NULL or pointer to command node
 */
_cool_command *cool_space_parser(char *pointer, char *cmd_line)
{
	size_t i = 0;
	char *cool_string = NULL;
	const char *arg_sep = " \n";
	_cool_command *cool_pointer = NULL;

	cool_string = strtok(cmd_line, arg_sep); /* get the first token */
    if (cool_string)
    {
        cool_pointer = cool_2_pointer(myself);
        add_tok_to_cmd(myself, cool_pointer, i, cool_string);
        while (cool_string != NULL)
        { /* walk through other tokens */
            i++;
            cool_string = strtok(NULL, arg_sep);
            if (cool_string)
                add_tok_to_cmd(myself, cool_pointer, i, cool_string);
        }
    }
    return (cool_pointer);
}
