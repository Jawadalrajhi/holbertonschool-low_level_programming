#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the new hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *table;
    unsigned long int i;

    table = malloc(sizeof(hash_table_t));
    if (table == NULL)
        return (NULL);

    table->array = malloc(sizeof(hash_node_t *) * size);
    if (table->array == NULL)
    {
        free(table);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        table->array[i] = NULL;

    table->size = size;

    return (table);
}
