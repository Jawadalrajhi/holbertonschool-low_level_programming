#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/* 1. shash_table_create */
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

/* 2. shash_table_set */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *node, *new_node;

	if (!ht || !key || !*key || !value)
	return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];

	while (node)
	{
	if (strcmp(node->key, key) == 0)
	{
	free(node->value);
	node->value = strdup(value);
	if (!node->value)
	return (0);
	return (1);
	}
	node = node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
	free(new_node->key);
	free(new_node->value);
	free(new_node);
	return (0);
	}

	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	insert_sorted(ht, new_node); /* separate function in 100-insert_sorted.c */

	return (1);
}

/* 3. shash_table_get */
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

/* 4. shash_table_print */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht)
	return;

	printf("{");
	node = ht->shead;
	while (node)
	{
	if (!first)
	printf(", ");
	printf("'%s': '%s'", node->key, node->value);
	first = 0;
	node = node->snext;
	}
	printf("}\n");
}

/* 5. shash_table_print_rev */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht)
	return;

	printf("{");
	node = ht->stail;
	while (node)
	{
	if (!first)
	printf(", ");
	printf("'%s': '%s'", node->key, node->value);
	first = 0;
	node = node->sprev;
	}
	printf("}\n");
}

