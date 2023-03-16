#include "main.h"
#include <stdlib.h>

/**
 * _calloc: allocate memory for an array using malloc
 * @nmeb: size of array
 * @size: size of each single array element
 * @array: array to be allocated memory *
 * Return: pointer to the allocated memory if success, if nmemb or size is 0 return NULL, if fail return NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *array;

	if (nmemb == 0 || size == 0)
		return (NULL);
	array = malloc(nmemb*size);
	if (array == NULL)
		return (NULL);
	return (array);

}
