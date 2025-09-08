#include "main.h"

/**
 * _sqrt_recursion - returns natural square root of n
 * @n: number to calculate sqrt of
 *
 * Return: sqrt of n, -1 if n does not have a natural sqrt
 */
int _sqrt_helper(int n, int i);

int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return _sqrt_helper(n, 0);
}

int _sqrt_helper(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return _sqrt_helper(n, i + 1);
}

