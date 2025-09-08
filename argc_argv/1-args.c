#include <stdio.h>

/**
 * main - prints the number of arguments passed into the program
 * @argc: number of arguments
 * @argv: array of argument strings (unused)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
(void)argv; /* argv is unused */

/* Print the number of arguments passed, excluding program name */
printf("%d\n", argc - 1);
return (0);
}
