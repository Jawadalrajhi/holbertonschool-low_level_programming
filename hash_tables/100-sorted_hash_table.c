#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the array
 *
 * Return: Pointer to the new hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return NULL;

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (!ht->array)
    {
        free(ht);
        return NULL;
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

/**
 * create_node - Creates a new sorted hash node
 */
shash_node_t *create_node(const char *key, const char *value)
{
    shash_node_t *node = malloc(sizeof(shash_node_t));
    if (!node)
        return NULL;
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = node->sprev = node->snext = NULL;
    return node;
}

/**
 * insert_sorted - Inserts node into sorted linked list
 */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
    shash_node_t *current;

    if (!ht->shead) /* first node */
    {
        ht->shead = ht->stail = node;
        return;
    }

    current = ht->shead;
    while (current && strcmp(node->key, current->key) > 0)
        current = current->snext;

    if (!current) /* insert at end */
    {

