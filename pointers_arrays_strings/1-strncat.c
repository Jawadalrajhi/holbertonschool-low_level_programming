#include "main.h"

/**
 * _strncat - concatenates at most n bytes from src
 *            to the end of dest
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of bytes to append from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* Find the end of dest */
	while (dest[i] != '\0')
		i++;

	/* Append at most n characters from src */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Null-terminate dest */
	dest[i] = '\0';

	return (dest);
}
