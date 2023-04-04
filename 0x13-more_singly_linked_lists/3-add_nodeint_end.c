#include "lists.h"

/**
 *add_nodeint_end - adds a new node at the end  of a list_t list
 *@head: a ptr to the head of listint_t list
 *@n: the number to be added to the listint_t list
 *@ptr: the pointer to
 *@tem: the node to be added	
 *Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *ptr, *tem;

	ptr  = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);



	ptr->n = n;
	ptr->next = NULL;

	if (*head == NULL)
		*head = ptr;
	else
	{
		tem = *head;
		while (tem->next != NULL)
			tem = tem->next;
		tem->next = ptr;
	}
	return (*head);
}
