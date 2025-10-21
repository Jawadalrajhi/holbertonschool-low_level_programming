#include "hash_tables.h"
#include <stdlib.h>

/***
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the new hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		ruturn(NULL);
}
