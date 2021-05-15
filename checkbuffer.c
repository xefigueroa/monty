#include "monty.h"

/**
 * checkbuffer - Will check buffer line by line
 * @fd: file descriptor
 * @buffer: buffer
 */

/*void checkbuffer(FILE *fd, char *buffer, ssize_t _read)*/
void checkbuffer(FILE *fd, char *buffer)
{
	char *delim = "\n\t ,.;:", *token = NULL;
	stack_t *head = NULL;
	int line = 1;
	size_t getSize = 1024;

	while ((getline(&buffer, &getSize, fd)) != EOF)
	{
		token = strtok(buffer, delim);
		if (token == NULL)
		{
			line++;
			continue;
		}
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			_isanum(token, line);
			addnode(&head, atoi(token));
			/*addEndNode(&head, atoi(token));*/
		}
		else
		{
			if (opfunc(token) != 0)
			{
				opfunc(token)(&head, line);
			}
			else
			{
				line++;
				freeList(head);/*maybe add free and fclose*/
				fprintf(stderr, "L%d: unknown instruction %s\n", line, buffer);
				exit(EXIT_FAILURE);
			}
		}
		line++;
	}
	freeList(head);
	free(buffer);
	fclose(fd);
}
