#include "shell.h"

/**
 * strlength - length of string
 * @string: string
 * Return: number of string
 */
size_t strlength(char *string)
{
	size_t k = 0;

	while (string[k] != '\0')
		k++;
	return (k);
}

/**
 * *strdupl - string duplication
 * @string: string
 *
 * Return: 0|1|-1 to repected succuess or error
 */
char *strdupl(char *string)
{
	int k = 0;
	int bul = 0;
	char *pt;

	if (string == NULL)
		return (NULL);
	while (string[bul])
	bul++;
	pt = malloc(bul * sizeof(char) + 1);
	if (!pt)
	{
		return (NULL);
	}
	for (k = 0; k < bul; k++)
	pt[k] = string[k];
	pt[k] = '\0';
	return (pt);
}

/**
 * strcom - string comparisons
 * @string: string 1
 * @strr: string 2
 *
 * Return: 1|-1
 */
int strcom(char *string, char *strr)
{
	int match = 0;
	int k = 0;

	while (*(string + k) && *(strr + k))
	{
		if (string[k] != strr[k])
			return (string[k] - strr[k]);
		match += string[k] - strr[k];
		k++;
	}
	return (match);
}

/**
 * str_conc - Function that concatenates two strings
 * @string: string 1
 * @strr: string 2
 * @num: number
 *
 * Return: -1|1
 */

char *str_conc(char *string, char *strr, unsigned int num)
{
	int k = 0, l = 0;
	int leng = 0;
	char *ptr;

	if (strr == NULL)
		strr = "";
	if (string == NULL)
		string = "";
	leng = strlength(strr);
	if (num >= (unsigned int)leng)
	{
		ptr = malloc(strlength(string) + leng + 1);
	}
	else
	{
		ptr = malloc(strlength(string) + num + 1);
	}
	if (!ptr)
	{
		return (NULL);
	}
	for (k = 0; string[k]; k++)
		ptr[k] = string[k];
	if (num >= (unsigned int)leng)
	{
		for (l = 0; string[l]; l++, k++)
		{
			ptr[k] = strr[l];
		}
	}
	else
	{
		for (l = 0; (unsigned int)l < num; l++, k++)
			ptr[k] = strr[l];
	}
	ptr[k] = '\0';
	return (ptr);
}
/**
 * *strcoin - coincidation of numbers
 * @adam: pointer char
 * @kalli: pointer char
 *
 * Return: -1|1
 */
char *strcoin(char *adam, char *kalli)
{
	int k = 0,  l;
	int cnt = 0;
	int kalli_bulk= 0;
	int place;

	while (*(kalli + kalli_bulk))
	kalli_bulk++;
	if (kalli_bulk == 0)
	{
		return (&adam[kalli_bulk]);
	}
	while (*(kalli + k))
	{
		l = 0;
		while (*(adam + l))
		{
			if (adam[l] == kalli[k])
			{
				cnt++;
				if (cnt == kalli_bulk)
			{
				place = l - cnt + 1;
			}
				break;
			}
			l++;
		}
		k++;
	}
	if (cnt == kalli_bulk)
	{
		return (&adam[place]);
	}
	return (NULL);
}
