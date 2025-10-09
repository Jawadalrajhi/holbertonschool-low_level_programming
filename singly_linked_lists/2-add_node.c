#include"lists.h"
/**
* add_node - adds a new node at the beginning
* @head: head
* @str: char
* Description: a function that adds a new node at the beginning
* Return: the address of the new element, or NULL if it failed
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	int i = 0;
	size_t length = 0;

	if (str == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	while (str[i])
	{
		length++;
		i++;
	}
	new_node->len = length;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
