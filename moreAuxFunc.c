#include "monty.h"

/**
 * _isanum - will verify if the character is a integer or not
 * @str: is the token to verify
 * @line: line number
 * Return: will return 1 if fails or 0 if not
 */

int _isanum(char *str, int line)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] < '0' || str[index] > '9')
		{
			printf("L<%d>: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

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
		printf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp2 = *head;

	temp->n = temp->n + temp2->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp2);
}
