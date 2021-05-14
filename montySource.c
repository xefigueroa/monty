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
	ssize_t _read;
	size_t getSize = 1024;
	char *buffer;
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
	checkbuffer(fd, buffer, _read);
	freeList(head);
	free(buffer);
	fclose(fd);
	return (0);
}
