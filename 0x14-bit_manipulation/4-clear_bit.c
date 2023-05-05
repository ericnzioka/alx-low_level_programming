#include "main.h"

/**
 * clear_bit: a function that sets the value of a bit to 0 at a given index
 * @n:  number to be modified
 * @index: index of  number to be modified
 * Return: 1 if it worked, or -1 if an error occurred
**/

int clear_bit(unsigned long int *n, unsigned int index)
{
		if (index < sizeof(unsigned long int) * 8)
{
		*n &= (~(1 << index));
		return (1);
		}

			return (-1);
}
