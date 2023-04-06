#include "main.h"
/**
 *flip_bits-counts how many bits need to be flipped in n to be m
 *@n: the original number
 *@m: the number n would flip into
 *Return: the number of bits that would need to be flipped for n to became m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int results;
	unsigned int counted;

	counted = 0;
	results = n ^ m;
	while (results != 0)
	{
		if ((results & 1) == 1)
			counted++;
		results = results >> 1;
	}
	return (counted);
}