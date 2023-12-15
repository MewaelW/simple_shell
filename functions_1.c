#include "main.h"

/**
 * _strcat - this function concatenates two strings
 *
 * @dest: char ptr
 * @src: const char ptr
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	int x, z;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (z = 0; src[z] != '\0'; z++)
	{
		dest[x] = src[z];
		z++;
	}

	dest[x] = '\0';
	return (dest);
}

/**
 * *_strcpy - This function Copies the string pointed to by src
 *
 * @dest: Type char pointer
 * @src: Type char pointer
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Is a  Function that compares two strings
 *
 * @s1: type str a
 * @s2: type str b
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;

	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}

/**
 * _strchr -This function locates a character in a string
 *
 * @s: str
 * @c: char
 * Return: ptr
 */

char *_strchr(char *s, char c)
{
	unsigned int x = 0;

	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}

/**
 * _strspn -This function gets the length of a prefix substring
 *
 * @s: initial seg
 * @accept: bytes
 * Return: the number of bytes
 */

int _strspn(char *s, char *accept)
{
	int c, b, bool;

	for (c = 0; *(s + c) != '\0'; c++)
	{
		bool = 1;
		for (b = 0; *(accept + b) != '\0'; b++)
		{
			if (*(s + c) == *(accept + c))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (c);
}
