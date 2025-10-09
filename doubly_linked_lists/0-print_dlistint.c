#include"lists.h"
/**
* print_dlistint - prints all the elements
* @h: head
* Description: a function that prints all the elements
* Return: the number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		counter++;
	}
	return (counter);
}

