#include "shell.h"

/**
 * *cool_node_add - Add nessary node
 * @string: he string
 *
 * Return: On success 1
 */
int cool_node_add(record_ **tip, char *string)
{
	record_ *wani = malloc(sizeof(tip));
	record_ *sabo = malloc(sizeof(tip));
	if (!sabo)
	{
		cool_free_list(*tip);
		return (-1);
	}

	sabo->rec = strdupl(string);

	if (sabo->rec == NULL)
	{
		cool_free_list(*tip);
		return (-1);
	}
	sabo->prv = NULL;
	sabo->nxt = NULL;
	if (!*tip)
	{
		*tip = sabo;
	}
	else
	{
		sabo->nxt = wani;
		*tip = sabo;
	}
	return (1);
}

