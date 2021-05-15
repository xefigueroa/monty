#include "monty.h"

/**
 * _add - add two
 * @head: pointer to head of stack
 * @line: line number
 */

void _add(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	temp->n = temp->n + temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}

/**
 * _sub - substract two
 * @head: pointer to head of stack
 * @line: line number
 */

void _sub(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	temp->n = temp->n - temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}

/**
 * _div - divide two
 * @head: pointer to head of stack
 * @line: line number
 */

void _div(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	if (temp2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	temp->n = temp->n / temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}

/**
 * _mul - multiply two
 * @head: pointer to head of stack
 * @line: line number
 */

void _mul(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	temp->n = temp->n * temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}

/**
 * _mod - calculate modulo of two
 * @head: pointer to head of stack
 * @line: line number
 */

void _mod(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	if (temp2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	temp->n = temp->n % temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}
