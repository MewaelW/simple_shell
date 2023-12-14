#include "main.h"

/**
 * read_line - This reads the input
 *
 * @ie: return value of getline
 * Return: input string
 */

char *read_line(int *ie)
{
	char *in = NULL;
	size_t buf = 0;

	*ie = getline(&in, &buf, stdin);

	return (in);
}
