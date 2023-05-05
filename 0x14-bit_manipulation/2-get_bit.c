#include "main.h"

/**
 * get_bit: a function that returns the value of a bit at a given index.
 * @n: number to  be evaluated
 * @index: index
 * Return: Value of bit at index, or -1 if error occured.
**/

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int value;

	if (index > 100)
		return (-1);
	value = n >> index;

	return (value & 1);
}
