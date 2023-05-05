#include "main.h"
/**
 *set_bit: function that sets the value of a bit to 1
 *@n: a pointer to a bit
 *@index: the index to set the value
 *Return: if an error return occure -1 otherwise succes return 1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (8 * sizeof(unsigned long int)))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
