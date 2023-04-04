#include "lists.h"
#include <stdio.h>
/**
 *print_listint- a function that list all elemnts of list_t
 *@h: The listint_t list *
 *@node: The list
 *Return: the number of nodes in h
 */
size_t print_listint(const listint_t *h)
{
	size_t node = 0;

	while (h)
	{

		printf("%d\n", h->n);
		node++;
		h = h->next;
	}
	return (node);
}
