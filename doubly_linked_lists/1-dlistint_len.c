#include"lists.h"
/**
* dlistint_len - returns the number of elements
* @h: head
* Description: a function that returns the number of elements
* Return: the number of nodes
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		h = h->next;
		counter++;
	}
	return (counter);
}
