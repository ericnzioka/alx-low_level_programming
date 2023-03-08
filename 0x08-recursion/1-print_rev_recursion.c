#include "main.h"
#include <string.h>
/**
 *_print_rev_recursion- print a string in a new line
 *@s: string to be reversed
 */

int len = strlen(*s);

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_putchar(*(s + len));
		_print_rev_recursion(s);
		len --;
	}
	else 
		_putchar('\n')
}
