#include "monty.h"

/**
 *opfunc - will get the function to do the operation that we need
 *@token: token
 *Return: the pointer to a function
 */

void (*opfunc(char *token))(stack_t **stack, unsigned int line)
{
	instruction_t inst[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"nop", _nop},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};

	int i = 0;

	while (inst[i].f != NULL)
	{
		if (strcmp(token, inst[i].opcode) == 0)
			return (inst[i].f);
		i++;
	}
	return (NULL);
}
