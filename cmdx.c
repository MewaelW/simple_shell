#include "main.h"

/**
 * is_cdir - This function checks for ":"  in the current directory
 *
 * @path: type char pointer
 * @i: type int pointer.
 * Return: 1 (success)
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - This one locates a command
 *
 * @cmd:The command name
 * @_environ: environment var
 * Return: location of command
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dirc;
	int len_dir, len_cmd, a;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		a = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &a))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dirc = malloc(len_dir + len_cmd + 2);
			_strcpy(dirc, token_path);
			_strcat(dirc, "/");
			_strcat(dirc, cmd);
			_strcat(dirc, "\0");
			if (stat(dirc, &st) == 0)
			{
				free(ptr_path);
				return (dirc);
			}
			free(dirc);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - This function determines if is an executable
 *
 * @datash: data
 * Return: 0
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int a;
	char *input;

	input = datash->args[0];
	for (a = 0; input[a]; a++)
	{
		if (input[a] == '.')
		{
			if (input[a + 1] == '.')
				return (0);
			if (input[a + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[a] == '/' && a != 0)
		{
			if (input[a + 1] == '.')
				continue;
			a++;
			break;
		}
		else
			break;
	}
	if (a == 0)
		return (0);

	if (stat(input + a, &st) == 0)
	{
		return (a);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - This function verifies if user
 * has permissions to access
 *
 * @dir: destination
 * @datash: data
 * Return: 1
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - This function executes command lines
 *
 * @datash: data
 * Return: 1
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exe;
	char *dir;
	(void) wpd;

	exe = is_executable(datash);
	if (exe == -1)
		return (1);
	if (exe == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exe == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exe, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
