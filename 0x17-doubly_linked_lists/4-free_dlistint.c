#include "lists.h"

/**
 * free_dlistint - Free a linked dlistint_t list.
 * @head: The head of the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *buff;

	while (head)
	{
		buff = head->next;
		free(head);
		head = buff;
	}
}
