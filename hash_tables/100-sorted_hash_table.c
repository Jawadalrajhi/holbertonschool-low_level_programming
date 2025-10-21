#include "hash_tables.h"

/* Helper to insert node in the sorted linked list */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;

	if (!ht->shead || strcmp(node->key, ht->shead->key) < 0)
	{
		node->snext = ht->shead;
		node->sprev = NULL;
		if (ht->shead)
			ht->shead->sprev = node;
		else
			ht->stail = node;
		ht->shead = node;
		return;
	}

	current = ht->shead;
	while (current->snext && strcmp(node->key, current->snext->key) < 0)
		current = current->snext;

	node->snext = current->snext;
	node->sprev = current;
	if (current->snext)
		current->snext->sprev = node;
	else
		ht->stail = node;
	current->snext = node;
}

/* 1. Create a sorted hash table */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/* 2. Set a key/value pair */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node, *new_node;
	char *val_copy;

	if (!ht || !key || !*key || !value)
		return (0);

	val_copy = strdup(value);
	if (!val_copy)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = val_copy;
			return (1);
		}
		node = node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	{
		free(val_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(val_copy);
		free(new_node);
		return (0);
	}

	new_node->value = val_copy;
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	insert_sorted(ht, new_node);

	return (1);
}

/* 3. Get value by key */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *node;

	if (!ht || !key || !*key)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/* 4. Print sorted hash table */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *sep = "";

	if (!ht)
		return;

	printf("{");
	for (node = ht->shead; node; node = node->snext)
	{
		printf("%s'%s': '%s'", sep, node->key, node->value);
		sep = ", ";
	}
	printf("}\n");
}

/* 5. Print sorted hash table in reverse */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *sep = "";

	if (!ht)
		return;

	printf("{");
	for (node = ht->stail; node; node = node->sprev)
	{
		printf("%s'%s': '%s'", sep, node->key, node->value);
		sep = ", ";
	}
	printf("}\n");
}

/* 6. Delete sorted hash table */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *tmp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}
	free(ht->array);
	free(ht);
}

