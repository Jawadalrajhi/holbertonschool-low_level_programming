#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: 0 on success
 */
int main(void)
{
int sum = 0;
int ch;

srand(time(NULL));

while (sum < 2772)
{
ch = rand() % 128;  /* random ASCII character */
if ((sum + ch) > 2772)
break;
sum += ch;
putchar(ch);
}

/* print the last char to reach exactly 2772 */
putchar(2772 - sum);

return (0);
}
