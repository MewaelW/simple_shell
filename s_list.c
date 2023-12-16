#include "main.h"

/**
 * free_line_list - This function frees line_list
 *
 * @head: linked list head
 * Return: none
 */

void free_line_list(line_list **head)
{
	line_list *tmp;
	line_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*head = NULL;
	}
}


/**
 * add_rvar_node - This adds a variable at the end
 * of a list
 * @head: head of linked list.
 * @lvar: length of  var
 * @val: value of var
 * @lval: length of value
 * Return: address of head
 */

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *n, *tmp;

	n = malloc(sizeof(r_var));
	if (n == NULL)
		return (NULL);

	n->len_var = lvar;
	n->val = val;
	n->len_val = lval;

	n->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = n;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
	}

	return (*head);
}

/**
 * free_rvar_list - frees list
 * @head: head of linked list
 * Return: none
 */

void free_rvar_list(r_var **head)
{
	r_var *tmp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tmp = curr) != NULL)
		{
			curr = curr->next;
			free(tmp);
		}
		*head = NULL;
	}
}
