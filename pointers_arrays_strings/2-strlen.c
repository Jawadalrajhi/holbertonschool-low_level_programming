#include "main.h"

/**
  * _strlen - len of string
  * @s: string will counts
  *
  * Return: number of len
  */
int _strlen(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}

	return (c);
}
