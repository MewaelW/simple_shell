#include "main.h"

/**
 * cmp_env - This function compares env variables names
 *
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if not equal
 */
int cmp_env(const char *nenv, const char *name)
{
	int j;

	for (j = 0; nenv[j] != '='; j++)
	{
		if (nenv[j] != name[j])
		{
			return (0);
		}
	}

	return (j + 1);
}

/**
 * _getenv - This gets an environment variable
 *
 * @name: name of the environment var
 * @_environ: environment var
 *
 * Return: value of the environment var
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr;
	int i, mov;

	/* Initialize */
	ptr = NULL;
	mov = 0;
	/* Compare all environment vars */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env(_environ[i], name);
		if (mov)
		{
			ptr = _environ[i];
			break;
		}
	}

	return (ptr + mov);
}

/**
 * _env - This function prints the evironment vars
 *
 * @datash: data
 * Return: 1
 */
int _env(data_shell *datash)
{
	int a, j;

	for (a = 0; datash->_environ[a]; a++)
	{

		for (j = 0; datash->_environ[a][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[a], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
