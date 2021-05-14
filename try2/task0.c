#include "monty.h"

/**
 * push - adds a new node at the beginning of a stack_t list,
 * or in queue mode, add node to end
 *
 * @cmd: access specific data for command
 * Return: address of new node, or NULL if failed
 */

void push(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *new = NULL;
	stack_t *temp = NULL;

	if (h == NULL)
	{
		printf("L%d: usage: push integer\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

	if (*cmd->mode == 1)
	{

		new->n = cmd->arg;
		new->next = NULL;
		new->prev = NULL;

		if (*h == NULL)
		{
			*h = new;
			return;
		}

		temp = *h;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		return;
	}
	if (*h == NULL)
	{
		new->n = cmd->arg;
		new->next = *h;
		new->prev = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->n = cmd->arg;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * pall - prints all elements of a doubly linked list
 *
 * @cmd: data specific variables for command
 */

void pall(cmd_t *cmd)
{
	stack_t *h = *cmd->head;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
