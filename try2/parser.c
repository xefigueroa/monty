#include "monty.h"

/**
 * eval - evaluate operation
 * @line: line of input to parse
 * @h: head of doubly linked list
 * @t: tail of doubly linked list
 * @mode: stack or queue mode
 * @ln: line number being evaluated
 */
void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln)
{
	cmd_t cmd;

	cmd.mode = mode;
	cmd.line_number = ln;
	cmd.head = h;
	cmd.tail = t;

	if (parse(line, &cmd))
		run(&cmd);
}

/**
 * parse - parses line of input into tokens
 * @line: line of input to parse
 * @cmd: arguments to send to function
 * Return: 0 means to skip line, 1 means to continue
 */
int parse(char *line, cmd_t *cmd)
{
	char delims[] = " \t\r\n";
	char *op;
	char *arg;
	int siz;
	unsigned int ln = cmd->line_number;

	if (line == NULL)
		return (0);

	op = strtok(line, delims);

	if (op == NULL || op[0] == '#')
		return (0);

	if (strcmp(op, "stack") == 0)
	{
		*cmd->mode = 0;
		return (0);
	}

	if (strcmp(op, "queue") == 0)
	{
		*cmd->mode = 1;
		return (0);
	}

	if (strcmp(op, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (arg == NULL)
		{
			printf("L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		siz = strlen(arg);
		while (siz--)
		{
			if (siz == 0 && arg[siz] == '-')
				break;
			if (arg[siz] > 57 || arg[siz] < 48)
			{
				printf("L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		cmd->arg = atoi(arg);
		cmd->op = op;
		return (1);
	}
	cmd->op = op;

	return (1);
}

/**
 * run - run's specified function
 * @cmd: data to pass to function
 */
void run(cmd_t *cmd)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(cmd->op, funcs[i].opcode) == 0)
		{
			funcs[i].f(cmd);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", cmd->line_number, cmd->op);
	exit(EXIT_FAILURE);
}
