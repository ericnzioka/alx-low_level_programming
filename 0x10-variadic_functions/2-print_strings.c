#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 *print_strings- print strings
 *@separator: string b/n numbers
 *@n: numbers
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list string_list;
	unsigned int i;
	char *sting;

	va_start(string_list, n);
	for (i = 0; i < n; i++)
	{
		string = va_arg(string_list, char *);
		if (string != NULL)
			printf("%s", string);
		else
			printf("(nil)");
		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");
		       va_end(string_list);

}

