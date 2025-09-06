#include "main.h"
#include <stdio.h>

/**
  * print_array - print arry elements
  * @a: this is an array
  * @n: number of array elements
  *
  * Return: void
  */
void print_array(int *a, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		printf("%d", a[j]);

		if (j != (n - 1))
		{
			printf(", ");
		}
	}

	printf("\n");
}
