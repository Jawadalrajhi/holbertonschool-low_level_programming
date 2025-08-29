#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print all small alphabet except q and e
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
for (n = 'a'; n <= 'z'; n++)
{
if (n != 'e' && n != 'q')
{
putchar(n);
}
}
putchar('\n');
return (0);
}
