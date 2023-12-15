#include "main.h"

/**
 * check_env -This function checks the typed variable
 * if its an env var
 *
 * @h: head of the linked list
 * @in: input str
 * @data: data struct
 * Return: none
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, chr, a, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (a = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				add_rvar_node(h, a, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[a] == _envr[row][chr])
				a++;
			else
				break;
		}
	}

	for (a = 0; in[a]; a++)
	{
		if (in[a] == ' ' || in[a] == '\t' || in[a] == ';' || in[a] == '\n')
			break;
	}

	add_rvar_node(h, a, NULL, 0);
}

/**
 * check_vars - This function checks the typed variable for  $$ or $?
 *
 * @h: head of linked list
 * @in: input str
 * @st: last status of shell
 * @data: data struct
 * Return: none
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int a, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (a = 0; in[a]; a++)
	{
		if (in[a] == '$')
		{
			if (in[a + 1] == '?')
				add_rvar_node(h, 2, st, lst), a++;
			else if (in[a + 1] == '$')
			{
				add_rvar_node(h, 2, data->pid, lpd), a++;
			}
			else if (in[a + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[a + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[a + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[a + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[a + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + a, data);
		}
	}

	return (a);
}

/**
 * replaced_input -This function replaces string into variables
 *
 * @head: head of linked list
 * @input: input str
 * @new_input: new input str
 * @nlen: new len
 * Return: replaced string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int i, j, a;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (a = 0; a < indx->len_var; a++)
					j++;
				i--;
			}
			else
			{
				for (a = 0; a < indx->len_val; a++)
				{
					new_input[i] = indx->val[a];
					i++;
				}
				j += (indx->len_var);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - this function calls functions to replace string into vars
 *
 * @input: input str
 * @datash: data struct
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int len, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	len = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += len;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
