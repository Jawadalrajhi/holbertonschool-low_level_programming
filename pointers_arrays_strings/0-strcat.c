#include "main.h"

/**
 * _strcat - concatenates the string pointed to by src
 *           to the end of the string pointed to by dest
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
