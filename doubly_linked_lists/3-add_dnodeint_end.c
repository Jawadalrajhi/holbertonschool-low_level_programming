#include"lists.h"
/**
* add_dnodeint_end - adds a new node at the end
* @head: head
* @n: int
* Description: a function that adds a new node at the end
* Return: the address of the new element, or NULL if it failed
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_end, *temp;

	temp = *head;
	new_end = malloc(sizeof(dlistint_t));
	if (new_end == NULL)
		return (NULL);
	new_end->n = n;
	if (*head == NULL)
	{
		*head = new_end;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_end;
		new_end->prev = temp;
		temp = new_end;
	}
	return (new_end);
}
