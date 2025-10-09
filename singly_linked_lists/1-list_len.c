#include"lists.h"
/**
 * list_len - returns the number of elements
 * @h: list
 * Description: a function that returns the number of elements.
 * Return: the number of nodes
 */

size_t list_len(const list_t *h)
{
	size_t counter = 0;

	while (h)
	{
		h = h->next;
		counter++;
	}
	return (counter);
}
