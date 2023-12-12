#include "shell.h"
/**
 * cool_path - gets path
 * @enviroment: enviroment pointer
 *
 * Return: pointer
 */

char *cool_path(char **enviroment)
{
	char **ptr;
	char *keyy;
	char *cool_alt, *way;

	if (enviroment == NULL)
	{
		return (NULL);
	}

	for (ptr = enviroment; ptr != 0; ptr++)
	{
		cool_alt =  strcoin(*ptr, "PATH");
		if (cool_alt != NULL)
		{
			way = strdupl(cool_alt);
			keyy = strtok(way, "=");
			while (keyy != NULL)
			{
				keyy = strtok(NULL, "=");
				return (keyy);
			}
		}
	}
	return (NULL);
}

/**
 * cool_find - finds directory of entry
 * @path_k: path
 * @cool_ar: entry pointer
 *
 * Return: derectory or path
 */

char *cool_find(char *path_k, char *cool_ar)
{
	char *way;
	char *key_path;
	char *arr, *instruction;
	unsigned int bulk;

	bulk = strlength(cool_ar);
	way = strdupl(path_k);
	arr = strdupl(str_conc("/", cool_ar, bulk));
	bulk = strlength(arr);
	key_path = strtok(way, ":");
	while (key_path != NULL)
	{
		instruction = str_conc(key_path, arr, bulk);
		if (access(instruction, F_OK) == 0)
			return (instruction);
		key_path = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * cool_print_env - Print environment
 *
 * @enviroment: Env var
 */

void cool_print_env(char **enviroment)
{
	char **ptr;
	unsigned int size;

	ptr = enviroment;
	while (*ptr)
	{
		size = strlength(*ptr);
		write(STDOUT_FILENO, *ptr, size);
		write(STDOUT_FILENO, "\n", 1);
		ptr++;
	}
}
