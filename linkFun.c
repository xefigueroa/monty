#include "monty.h"

/**
 *addEndNode - will add a new node to the end of the list
 *@head: is the address of the first node
 *@n: is the value of the nodes
 *Return: will return the new node
 */


stack_t *addEndNode(stack_t **head, const int n)
{
	stack_t *new_node, *end_node;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	end_node = *head;

	while (end_node->next != NULL)
	{
		end_node = end_node->next;
	}

	end_node->next = new_node;
	new_node->prev = end_node;

	return (new_node);
}


/**
 *addnode - will add a new node to the list
 *@head: is the address of the first node
 *@n: is the value of the nodes
 *Return: will return the new node
 */

stack_t *addnode(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;

	if (new_node->next)
	{
		new_node->next->prev = new_node;
	}
	return (new_node);
}

/**
 *freeList - will free every node in the list using a pointer
 *@head: will be always the head of nodes
 *Return: will return nothing (void)
 */

void freeList(stack_t *head)
{
	stack_t *ptrHead;

	while (head != NULL)
	{
		ptrHead = head;
		head = head->next;
		free(ptrHead);
	}
}
