#include "main.h"
#include <stdlib.h>

/**
 * array_range: creates an array of integers
 * @min: limit
 * @mx: limit
 * @i: iteration index
 * @array: newly created array
 * Return: array if succes, if fail NULL, if min > max return NULL.
 */

int *array_range(int min, int max)
{
	int *array;
	int n;
	int i;

	if(min > max)
		return (NULL);
	n = max - min + 1;
	array = malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		array[i] = min + i;
	}
	if (array == NULL)
		return (NULL);
	return(array);
}
