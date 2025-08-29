#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print all small alphabeti in reverse with a for loop
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
for (n = 'z'; n >= 'a'; n--)
{
putchar(n);
}
putchar('\n');
return (0);
}
