#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *        by emitting printable ASCII chars whose byte-sum is 2772
 *
 * Return: 0 on success
 */
int main(void)
{
	int sum = 0;
	int ch;

	srand((unsigned int)time(NULL));

	/* keep picking printable bytes [33..126] until the sum hits 2772 */
	while (sum != 2772)
	{
		/* pick a printable ASCII char */
		ch = (rand() % (126 - 33 + 1)) + 33;

		/* only print/use it if it doesn't overshoot 2772 */
		if (sum + ch <= 2772)
		{
			putchar(ch);
			sum += ch;
		}
	}

	/* no trailing newline; the checker pipes the output directly */
	return (0);
}

