#include "main.h"

/**
 * get_len - This function gets
 * the length of a number
 *
 * @n: int
 * Return: Length of number
 */

int get_len(int n)
{
	unsigned int nn;
	int len = 1;

	if (n < 0)
	{
		len++;
		nn = n * -1;
	}
	else
	{
		nn = n;
	}
	while (nn > 9)
	{
		len++;
		nn = nn / 10;
	}

	return (len);
}

/**
 * aux_itoa - This function converts int into string
 *
 * @n: int
 * Return: Str
 */

char *aux_itoa(int n)
{
	unsigned int nn;
	int len = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (n < 0)
	{
		nn = n * -1;
		buffer[0] = '-';
	}
	else
	{
		nn = n;
	}

	len--;
	do {
		*(buffer + len) = (nn % 10) + '0';
		nn = nn / 10;
		len--;
	}
	while (nn > 0)
		;
	return (buffer);
}

/**
 * _atoi - This function converts a string into an int
 *
 * @s: string
 * Return: integer
 */

int _atoi(char *s)
{
	unsigned int counter = 0, len = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + counter) != '\0')
	{
		if (len > 0 && (*(s + counter) < '0' || *(s + counter) > '9'))
			break;

		if (*(s + counter) == '-')
			pn *= -1;

		if ((*(s + counter) >= '0') && (*(s + counter) <= '9'))
		{
			if (len > 0)
				m *= 10;
			len++;
		}
		counter++;
	}

	for (i = counter - len; i < counter; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
