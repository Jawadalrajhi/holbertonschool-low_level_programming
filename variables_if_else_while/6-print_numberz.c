#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: print numbers from 0 to 9 with a for loop using putchar()
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
for (n = '0'; n <= '9'; n++)
{
putchar(n);
}
putchar('\n');
return (0);
}
