#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/*This Points to an array of pointers  "environment" */
extern char **environ;
/**
 * struct data - This contains all the data needed on runtime
 *
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @count: line counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int count;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - This is a single linked list
 *
 * @separator: ; | &
 * @next: next node
 * Description: The single linked list stores separators
 */
typedef struct sepa_list_s
{
	char separator;
	struct sepa_list_s *next;
} sepa_list;

/**
 * struct line_list_s - This is a single linked list
 *
 * @c_line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - This is a single linked list
 *
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - This Builtin struct is for command args
 *
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* read.c */
char *read(int *ie);

/* get_line.c */
void bring(char **lineptr, size_t *n, char *buffer, size_t i);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

#endif
