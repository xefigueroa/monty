#include "monty.h"

/**
 *main - is the source code (will call other functions if need it)
 *@argc: will count the arguments
 *@argv: will get the file to interprete
 *Return: will return 0
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	int line = 1;
	ssize_t _read;
	size_t getSize = 1024;
	char *buffer, *token = NULL, *delim = " \n";
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	_read = getline(&buffer, &getSize, fd);
	if (_read == -1)
	{
		free(buffer);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	while (_read != EOF)
	{
		token = strtok(buffer, delim);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			_isanum(token, line);
			/*addEndNode(&head, atoi(token));*/
			addnode(&head, atoi(token));
			line++;
		}
		else
		{
			if (opfunc(token) != 0)
			{
				opfunc(token)(&head, line);
			}
			else
			{
				freeList(head);/*maybe add free and fclose*/
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
			line++;
		}
		_read = getline(&buffer, &getSize, fd);
	}
	freeList(head);
	free(buffer);
	fclose(fd);
	return (0);
}
