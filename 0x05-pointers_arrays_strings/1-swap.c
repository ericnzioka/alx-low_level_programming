#include "main.h"

/**
 *swap_int- interchanges a and b
 *@a: checked
 *@b: checked
 *Return: nothing
 */

void swap_int(int *a, int *b)
{
	int p;
	
	p = *a;

	*a = *b;

	*b = p;
}
