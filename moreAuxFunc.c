#include "monty.h"

/**
 * _isanum - will verify if the character is a integer or not
 * @token: is the token to verify
 * @line: line number
 * Return: will return 1 if fails or 0 if not
 */

int _isanum(char *token, int line)
{
	int index;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	for (index = 0; token[index] != '\0'; index++)
	{
		if (token[index] == '-')
		{
			if (isdigit(token[index + 1]) == 1)
			{
				return (0);
			}
		}
		else if (isdigit(token[index]) == 1)
		{
			return (0);
		}
		else if (token[index] < '0' || token[index] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

/**
 *_pchar - will print the value at the top of the stack as ascii character
 *@head: is the pointer to the first node
 *@line: number of the line
 */

void _pchar(stack_t **head, unsigned int line)
{
	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) >= 0 && ((*head)->n) <= 127)
	{
		printf("%c\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}
