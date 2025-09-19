#include "main.h"
#include <stdlib.h>

/**
 * create_array - the function to use a specific char
 * @size: number of array size
 * @c: the char will be used in array
 *
 * Return: The array filled
 *
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *s;

	if (size == 0)
		return (NULL);

	s = malloc(size * sizeof(char));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		s[i] = c;
	}

	return (s);
}
