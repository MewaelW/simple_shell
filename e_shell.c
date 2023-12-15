#include "main.h"

/**
 * exit_shell - This one exits the shell
 *
 * @datash: data
 * Return: 0
 */
int exit_shell(data_shell *datash)
{
	unsigned int unstatus;
	int is_digit;
	int str_len;
	int big_num;

	if (datash->args[1] != NULL)
	{
		unstatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_num = unstatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_num)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (unstatus % 256);
	}
	return (0);
}
