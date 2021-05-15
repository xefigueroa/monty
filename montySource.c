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
	/*ssize_t _read;*/
	char *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	checkbuffer(fd, buffer);
	free(buffer);
	fclose(fd);
	return (0);
}
