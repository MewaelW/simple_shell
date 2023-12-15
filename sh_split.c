#include "main.h"

/**
 * swap_char -This function swaps | and & with non-printed chars
 *
 * @input: input str
 * @bool: type
 * Return: swapped str
 */
char *swap_char(char *input, int bool)
{
	int a;

	if (bool == 0)
	{
		for (a = 0; input[a]; a++)
		{
			if (input[a] == '|')
			{
				if (input[a + 1] != '|')
					input[a] = 16;
				else
					a++;
			}

			if (input[a] == '&')
			{
				if (input[a + 1] != '&')
					input[a] = 12;
				else
					a++;
			}
		}
	}
	else
	{
		for (a = 0; input[a]; a++)
		{
			input[a] = (input[a] == 16 ? '|' : input[a]);
			input[a] = (input[a] == 12 ? '&' : input[a]);
		}
	}
	return (input);
}

/**
 * add_nodes - This adds separators and command lines in the lists
 *
 * @head_s: head of separator
 * @head_l: head of command lines
 * @input: input str
 * Return: none
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int a;
	char *line;

	input = swap_char(input, 0);

	for (a = 0; input[a]; a++)
	{
		if (input[a] == ';')
			add_sep_node_end(head_s, input[a]);

		if (input[a] == '|' || input[a] == '&')
		{
			add_sep_node_end(head_s, input[a]);
			a++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * go_next - This goes to the next command line stored
 *
 * @list_s: separator li
 * @list_l: command line li
 * @datash: data struct
 * Return: none
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - This function splits command lines according to
 * the separators that executes them
 *
 * @datash: data struct
 * @input: input str
 * Return: 0 or 1
 */
int split_commands(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int lloop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		lloop = exec_line(datash);
		free(datash->args);

		if (lloop == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (lloop == 0)
		return (0);
	return (1);
}

/**
 * split_line - This fucntion tokenizes the input string
 *
 * @input: input str
 * Return: str splitted
 */
char **split_line(char *input)
{
	size_t bsize;
	size_t a;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": alloc error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (a = 1; token != NULL; a++)
	{
		if (a == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, a, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": alloc error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[a] = token;
	}

	return (tokens);
}
