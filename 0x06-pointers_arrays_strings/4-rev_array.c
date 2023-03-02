#include "main.h"
/**
 * reverse_array- prints the array in reverse
 *
 * @a: an array of intergers
 * @n: the number of elements to swap
 * Return: Always zero
 */
void reverse_array(int *a, int n)
{
	int i, j, b;

	i = 0;
	j = n - 1;

	while (i < j)
	{
		b = a[i];
		a[i] = a[j];
		a[j] = b;
		i++;
		j--;
	}
}
