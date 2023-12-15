#include "main.h"

/**
 * without_comment - This funciton deletes comments from input
 *
 * @in: input str
 * Return: input
 */

char *without_comment(char *in)
{
	int a, up_to;

	up_to = 0;
	for (a = 0; in[a]; a++)
	{
		if (in[a] == '#')
		{
			if (a == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[a - 1] == '\0' || in[a - 1] == '\t' || in[a - 1] == '\0')
				up_to = a;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, a, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - This is the shell loop
 *
 * @datash: data
 * Return: none
 */
void shell_loop(data_shell *datash)
{
	int loop, ie;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "$ ", 4);
		input = read_line(&ie);
		if (ie != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
