#include "shell.h"
#include <stdbool.h>
/**
 * cool_main - cool simple Shell
 * @argc: Argument count
 * @argv: Argument variables or content
 * @env: evironment variables value
 *
 * Return: 0 | 1
 */
int cool_main(int argc, char **argv, char **env)
{
	cool_instruction **cool_term = NULL;
	char *cool_path = NULL;

	path = get_path(env);
	argc++;
	while (true)
	{
		cool_term = cool_prompt(argv[0], argv[1]);
		if (cool_term)
		{
			if (cool_fork(argv[0], *cool_term, cool_path, env))
				cool_error_handl(argv[0], 74);
		}
		else
			cool_error_handl(argv[0], 75);
	}
	return (0);
}
