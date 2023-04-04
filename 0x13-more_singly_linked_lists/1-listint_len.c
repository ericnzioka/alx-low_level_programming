#include "lists.h"

/**
 *listint_len- counts the number of nodes
 *@h:ptr to the starting of the list
 *@nodes:the number of nodes
 *Return: the amount of elemnts in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}