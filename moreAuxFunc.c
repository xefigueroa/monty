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
			printf("L<%D>: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

