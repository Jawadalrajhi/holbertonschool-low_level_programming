#include"lists.h"
/**
* insert_dnodeint_at_index - inserts a new node at a given position
* @h: head
* @idx: index
* @n: int
* Description: a function that inserts a new node at a given position
* Return: the address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp, *updatr, *new_node;
	unsigned int i = 0, count = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	tmp = updatr = *h;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (idx >= count)
	{
		free(new_node);
		return (NULL);
	}
	tmp = *h;
	while (i < idx)
	{
		tmp = tmp->next;
		updatr = updatr->next;
		i++;
	}
	new_node = tmp;
	new_node->n = n;
	tmp = tmp->prev;
	while (updatr)
	{
		tmp->next = updatr;
		updatr->prev = tmp;
		tmp = tmp->next;
		updatr = updatr->next;
	}
	return (new_node);
}
