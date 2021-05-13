#include "monty.h"

/**
 *_push - will verify if the character is a integer or not
 *@str: is the token to verify
 *Return: will return 1 if fails or 0 if not
 */

int _push(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] < '0' || str[index] > '9')
		{
			return (1);
		}
	}
	return (0);
}
