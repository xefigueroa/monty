#include "monty.h"

/**
 * checkbuffer - Will check buffer line by line
 * @fd: file descriptor
 * @buffer: buffer
 * @_read: file lines read
 */

void checkbuffer(FILE *fd, char *buffer, ssize_t _read)
{
	char *delim = " \n", *token = NULL;
	stack_t *head = NULL;
	int line = 1;
	size_t getSize = 1024;

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

}
