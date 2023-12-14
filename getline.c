#include "main.h"

/**
 * bring - This function assigns the line var
 *
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of the line
 * @i: size of the buffer
 */

void bring(char **lineptr, size_t *n, char *buffer, size_t i)
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
 * get_line - This function reads input from stream
 *
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int j;
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
		j = read(STDIN_FILENO, &t, 1);
		if (j == -1 || (j == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j == 0 && input != 0)
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
	if (j != 0)
		input = 0;
	return (retval);
}
