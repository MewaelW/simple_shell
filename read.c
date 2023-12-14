#include "main.h"

/**
 * read - This reads the input
 *
 * @ie: return value of getline
 * Return: input string
 */

char *read(int *ie)
{
	char *in = NULL;
	size_t buf = 0;

	*ie = getline(&in, &buf, stdin);

	return (in);
}
