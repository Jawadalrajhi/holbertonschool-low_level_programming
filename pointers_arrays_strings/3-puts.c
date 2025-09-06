#include "main.h"

/**
  * _puts - print string using _putchar
  * @str: The string to print
  *
  * Return: void
  */
void _puts(char *str)
{
	for (; *str != '\0'; str++)
	{
		_putchar(*str);
	}

	_putchar('\n');
}
