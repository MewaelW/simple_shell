#include "main.h"

/**
 * error_path_126 - This displays an error message for path and
 * failure denied permission.
 *
 * @datash: data
 * Return: error string
 */

char *error_path_126(data_shell *datash)
{
	int length;
	char *str;
	char *error;

	str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(str);
	return (error);
}
