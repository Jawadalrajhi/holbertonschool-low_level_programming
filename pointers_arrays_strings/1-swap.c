#include "main.h"

/**
  * swap_int - change to  two integers
  *
  * @a: the integer will swap to @b
  * @b: another integer will swap to @a
  *
  * Return: void @a and @b after swap values
  */
void swap_int(int *a, int *b)
{
	int z;

	z = *a;
	*a = *b;
	*b = z;
}
