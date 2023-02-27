#include "main.h"

/**
 * print_rev: check 
 *
 * Return: nothing
 */

void print_rev(char *s)
{
	if (*s)
		for (i = s; s != 0; s-- )
		{
			_putchar(*s++)
		}	
		_putchar('\n');
}
