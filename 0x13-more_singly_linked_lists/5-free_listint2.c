#include "lists.h"
/**
 *free_listint2- free's listint_t and sets the head to NULL
 *@head: a ptr tp the listint_t list
 *@tem: a pointer to the head of the list 
 */
void free_listint2(listint_t **head)
{
	listint_t *tem;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		tem = (*head)->next;
		free(*head);
		*head = tem;
	}
	*head = NULL;
}
