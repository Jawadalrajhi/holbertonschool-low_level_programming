#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: natural square root of n, or -1 if n has no natural square root
 */
int _sqrt_recursion(int n);

/**
 * _sqrt_helper - recursive helper to find natural square root
 * @n: number to calculate the square root of
 * @i: iterator starting from 0
 *
 * Return: natural square root of n, or -1 if not found
 */
int _sqrt_helper(int n, int i);

int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_sqrt_helper(n, 0));
}

int _sqrt_helper(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return (_sqrt_helper(n, i + 1));
}
