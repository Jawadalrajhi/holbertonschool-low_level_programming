#include"lists.h"
/**
* free_list - frees a list
* @head: head
* Description: a function that frees a list
*/
void free_list(list_t *head)
{
	list_t *temp, *next_node;

	temp = head;
	while (temp)
	{
		next_node = temp->next;
		free(temp->str);
		free(temp);
		temp = next_node;
	}
}
