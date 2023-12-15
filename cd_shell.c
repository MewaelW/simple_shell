#include "main.h"

/**
 * cd_shell -This function changes the current directory
 *
 * @datash: data
 * Return: 1
 */
int cd_shell(data_shell *datash)
{
	char *dirc;
	int ishome, ishome2, isddash;

	dirc = datash->args[1];

	if (dirc != NULL)
	{
		ishome = _strcmp("$HOME", dirc);
		ishome2 = _strcmp("~", dirc);
		isddash = _strcmp("--", dirc);
	}

	if (dirc == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dirc) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dirc) == 0 || _strcmp("..", dirc) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
