#include "monty.h"

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
 *printNode - will print the elements as decimal
 *@h: will point to head node
 *Return: will return the count of elements
 */

size_t printNode(const stack_t *h)
{
	int count = 0;

	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL)
	{

		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
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
