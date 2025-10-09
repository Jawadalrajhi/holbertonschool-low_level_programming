#include"lists.h"
/**
* free_dlistint - frees a list
* @head: head
* Description: a function that frees a list
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp, *next_node;

	temp = head;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
}
