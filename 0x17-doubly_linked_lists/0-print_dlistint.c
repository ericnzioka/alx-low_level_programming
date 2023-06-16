#include "lists.h"
/**
 * print_dlistint - Prints all the the doubly linked list
 * @h: head of the list.
 * Return: The number of nodes in list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t node = 0;

	while (h)
	{
		node++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (node);
}
