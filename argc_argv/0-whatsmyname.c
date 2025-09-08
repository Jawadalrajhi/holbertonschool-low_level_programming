#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments (unused)
 * @argv: array of argument strings
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
    (void)argc; /* unused parameter */

    printf("%s\n", argv[0]);
    return (0);
}
