#include "main.h"
#include <stdlib.h>

/**
 * create_array- creates array
 * @c: checked
 * @size: size of array
 * Return: array
 */

char *create_array(unsigned int size, char c)
{
	char *array_of_chars;
	size_t i;

	if (size == 0)
		return (NULL);
	
	array_of_chars = malloc(size*sizeof(char));
	
	if (array_of_chars == NULL)
		return (NULL);
	for (i=0; i<size; 1++)
	{
		array_of_chars[i] = c;
	}
	return (array_of_chars);
}
