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
