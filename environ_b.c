#include "main.h"

/**
 * copy_info - This function copies info, creates
 * new env
 *
 * @name: name
 * @value: value
 *
 * Return: env
 */
char *copy_info(char *name, char *value)
{
	char *n;
	int len, len_value, len_name;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	n = malloc(sizeof(char) * (len));
	_strcpy(n, name);
	_strcat(n, "=");
	_strcat(n, value);
	_strcat(n, "\0");

	return (n);
}

/**
 * set_env - This function sets an environment var
 *
 * @name: name of environment var
 * @value: value of environment var
 * @datash: data structure
 * Return: none
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int j;
	char *var_env, *name_env;

	for (j = 0; datash->_environ[j]; j++)
	{
		var_env = _strdup(datash->_environ[j]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[j]);
			datash->_environ[j] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, j, sizeof(char *) * (j + 2));
	datash->_environ[j] = copy_info(name, value);
	datash->_environ[j + 1] = NULL;
}

/**
 * _setenv - This function compares env vars names with
 * the name passed
 *
 * @datash: data
 *
 * Return: 1
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - This function deletes an environment var
 *
 * @datash: data relevant
 *
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, a;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	a = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			a = i;
		}
		free(var_env);
	}
	if (a == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != a)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[a]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
