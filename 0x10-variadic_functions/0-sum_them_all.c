#include "variadic_functions.h"
#include <stdarg.h>

/**
 *sum_them_all- return the sum of all parm
 *@n: number of parm
 *@...: elipse
 *
 *Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list parameters;
	unsigned int i, sum = 0;

	if (n == 0)
		return (0);
	va_start(parameters, n);
	for (i = 0; i < n; i++)
		sum = sum + va_arg(parameters, int);
	va_end(parameters);
	return (sum);
}
