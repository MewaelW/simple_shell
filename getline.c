#include "main.h"

/**
 * bring_line - This function assigns the line var
 *
 * @lineptr: Buffer which stores the input str
 * @buffer: str that has been called to line
 * @n: size of line
 * @i: size of buffer
 */

void bring_line(char **lineptr, size_t *n, char *buffer, size_t i)
{

	if (*lineptr == NULL)
	{
		if  (i > BUFSIZE)
			*n = i;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < i)
	{
		if (i > BUFSIZE)
			*n = i;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - This function reads the input from stream
 *
 * @lineptr: the buffer which stores the input
 * @n: size of lineptr
 * @stream: stream
 * Return: number of bytes
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int a;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		a = read(STDIN_FILENO, &t, 1);
		if (a == -1 || (a == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (a == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (a != 0)
		input = 0;
	return (retval);
}
