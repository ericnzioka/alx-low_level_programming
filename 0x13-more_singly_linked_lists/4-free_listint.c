#include "lists.h"
/**
 *free_listint- free's listint_t
 *@head: a ptr tp the listint_t list
 *@tem: pointer 
 *Return: nothing
 */
void free_listint(listint_t *head)
{
	 listint_t *tem;


	while (head)
	{
		tem = head->next;
		free(head);
		head = tem;
	}
}
