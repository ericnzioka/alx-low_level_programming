#include "main.h"

/**
* flip_bits: a function that flips bits to convert one number to another number
* @n: first number
* @m: second number
* Return: number of bits that was needed to flip
**/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int delta;
	int count;

	delta = n ^ m;
	count = 0;

	while (delta)
	{
		count++;
		delta &= (delta - 1);
	}

	return (count);
}
