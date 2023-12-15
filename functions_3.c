#include "main.h"

/**
 * rev_string -This function reverses a string
 *
 * @s: input str
 * Return: none
 */

void rev_string(char *s)
{
	int a, b, count = 0;
	char *str, tmp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (a = 0; b < (count - 1); a++)
	{
		for (b = a + 1; b > 0; b--)
		{
			tmp = *(str + b);
			*(str + b) = *(str + (b - 1));
			*(str + (b - 1)) = tmp;
		}
	}
}
