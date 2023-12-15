#include "main.h"

/**
 * aux_help - This is a help information for the builtin help.
 *
 * Return: no return
 */

void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay The information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays the brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - This is a help information for the builtin alias
 *
 * Return: none
 */

void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - This is a help information for the builtin alias
 *
 * Return: none
 */

void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChanges the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - This is a help information fot the builint exit
 *
 * Return: no return
 */

void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell, with a status of N";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is the last executed command's\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
