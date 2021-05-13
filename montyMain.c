#include "monty.h"

/**
 *main - is the source code (will call other functions if need it)
 *@argc: will count the arguments
 *@argv: will get the file to interprete
 *Return: will return 0
 */

int main(int argc, char *argv[])
{
	int fd, line = 1;
	ssize_t _read;
	char *buffer, *token, *delim = "\n ";
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL)
	{
		return (0);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	_read = read(fd, buffer, 1024);

	if (_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			if (_push(token) == 1)
			{
				printf("L<%d>: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			addnode(&head, atoi(token));
			line++;
		}
		else if (strcmp(token, "pall") == 0)
		{
			printNode(head);
			line++;
		}
		else
		{
			printf("L<%d>: unknown instruction <%s>\n"
			       , line, token);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}

	freeList(head);
	close(fd);
	return (0);
}
