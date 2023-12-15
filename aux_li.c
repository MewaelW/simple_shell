#include "main.h"

/**
 * add_sep_node_end - This adds a separator at the end
 * of a sep_list
 *
 * @head: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */

sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *tmp, *new;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list -This function frees a sep_list
 *
 * @head: head of list
 * Return: none
 */

void free_sep_list(sep_list **head)
{
	sep_list *tmp;
	sep_list *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((tmp = cur) != NULL)
		{
			cur = cur->next;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - This function adds a command line at the end
 * of line_list
 *
 * @head: head
 * @line: The command line
 * Return: address of head
 */

line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *tmp, *new;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}
