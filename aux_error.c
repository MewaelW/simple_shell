#include "main.h"

/**
 * strcat_cd - this is a function that concatenates
 * the message for cd error
 *
 * @datash: data
 * @msg: message
 * @error: error message
 * @ver_str: line counter
 * Return: @error
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal = malloc(3);
		illegal[0] = '-';
		illegal[1] = datash->args[1][1];
		illegal[2] = '\0';
		_strcat(error, illegal);
		free(illegal);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - this function is for error messages for cd
 * command
 *
 * @datash: data
 * Return: error propmt
 */

char *error_get_cd(data_shell *datash)
{
	int len, len_y;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_y = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_y = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_y + 5;
	error = malloc(sizeof(char) * (len + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - A generic error message
 * for command not found
 *
 * @datash: data
 * Return: Error
 */

char *error_not_found(data_shell *datash)
{
	int l;
	char *error;
	char *ver;

	ver = aux_itoa(datash->counter);
	l = _strlen(datash->av[0]) + _strlen(ver);
	l += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (l + 1));
	if (error == 0)
	{
		free(error);
		free(ver);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver);
	return (error);
}

/**
 * error_exit_shell - A generic error message
 * for an exit
 *
 * @datash: data
 * Return: Error
 */

char *error_exit_shell(data_shell *datash)
{
	int len;
	char *error;
	char *er;

	er = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(er);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(er);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, er);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(er);

	return (error);
}


/**
 * error_env - An error message for env
 *
 * @datash: data
 * Return: error
 */

char *error_env(data_shell *datash)
{
	int l;
	char *error;
	char *ver;
	char *msg;

	ver = aux_itoa(datash->counter);
	msg = ": Unable to add or remove from environment\n";
	l = _strlen(datash->av[0]) + _strlen(ver);
	l += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (l + 1));
	if (error == 0)
	{
		free(error);
		free(ver);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver);

	return (error);
}

