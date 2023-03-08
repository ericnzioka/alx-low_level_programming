#include <main.h>

/**
 *_puts_recursion - prints a string followed by new line
 *@s: string to be printed
 */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recrsion(s + 1);
	}
	else
		_putchar(\n);
}
