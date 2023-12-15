#include "main.h"

/**
 * _strdup - This function duplicates a str in the heap memory
 *
 * @s: Type char ptr str
 * Return: str
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - This function returns the length of a string
 *
 * @s: Type char ptr
 * Return: Always 0
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - This function compares chars of strings
 *
 * @str: input str
 * @delim: delim
 * Return: 1 success
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int a, b, x;

	for (a = 0, x = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				x++;
				break;
			}
		}
	}
	if (a == x)
		return (1);
	return (0);
}

/**
 * _strtok - This function splits a string by a delimiter
 *
 * @str: input str
 * @delim: delim
 * Return: splited string
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		a = _strlen(str);
		str_end = &str[a];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (a = 0; delim[a]; a++)
		{
			if (*splitted == delim[a])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit -This funciton defines if a string passed is a number
 *
 * @s: input string
 * Return: 1 or 0
 */

int _isdigit(const char *s)
{
	unsigned int x;

	for (x = 0; s[x]; x++)
	{
		if (s[x] < 48 || s[x] > 57)
			return (0);
	}
	return (1);
}
