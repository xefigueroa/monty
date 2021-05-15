#include "monty.h"

/**
 *_pall - will print the nodes of the list
 *@head: will point to head node
 *@line: line number
 *Return: will return the count of nodes
 */

void _pall(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	(void)line;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 *_pint - will print the value at the top of the stack
 *@head: is the pointer to the first node
 *@line: number of the line
 */

void _pint(stack_t **head, unsigned int line)
{
	if (*head == NULL || head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 *_nop - a function that doesn't do shit
 *@head: is the pointer to the first node
 *@line: is the number of lines
 *Return: will return nothing (void)
 */

void _nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}

/**
 *_swap - will swap the first two elements of the stack
 *@head: is the pointer to the first node
 *@line: is the number of lines
 *Return: will return nothing (void)
 */

void _swap(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*head)->next->next == NULL)
	{
		temp = (*head)->next;
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		(*head)->next->next = NULL;
	}
	else
	{
		temp = *head;
		temp2 = (*head)->next;
		temp->next = temp2->next;
		temp2->next = temp;
		temp2->prev = NULL;
		temp->prev = temp2;
		temp->next->prev = temp;
		*head = temp2;
	}
}

/**
 *_pop - will delete the first element of the stack
 *@head: is the pointer to the first node
 *@line: is the number of lines
 *Return: will return nothing (void)
 */

void _pop(stack_t **head, unsigned int line)
{
	stack_t *delNode;
	(void)line;

	if (*head == NULL || head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	delNode = *head;

	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(delNode);
	}

	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(delNode);
	}
}
