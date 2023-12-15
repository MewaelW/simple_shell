#include "main.h"

/**
 * free_data - this funciton frees the data structure
 *
 * @datash: data struct
 * Return: none
 */

void free_data(data_shell *datash)
{
	unsigned int s;

	for (s = 0; datash->_environ[s]; s++)
	{
		free(datash->_environ[s]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data -  This function initializes the data struct
 *
 * @datash: data struct
 * @av: arg vector
 * Return: none
 */

void set_data(data_shell *datash, char **av)
{
	unsigned int d;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (d = 0; environ[d]; d++)
		;

	datash->_environ = malloc(sizeof(char *) * (d + 1));

	for (d = 0; environ[d]; d++)
	{
		datash->_environ[d] = _strdup(environ[d]);
	}

	datash->_environ[d] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - This is the main entry point
 *
 * @ac: arg c
 * @av: arg v
 * Return: 0
 */

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
