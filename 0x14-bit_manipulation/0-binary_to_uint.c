#include "main.h"

/**
 *binary_to_uint - convert a binary number to unsigned int
 *@b:a pointer to a string of 0 & 1 chars
 *@weight:conversion coefficient
 *@sum: converted int
 *Return: converted number or if b is NULL or contains chars not 0 or 1 - 0.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0, weight = 1;
	int len;

	if (b == '\0')
		return (0);

	for (len = 0; b[len]; len++);

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		sum += (b[len] - '0') * weight;
		weight *= 2;
	}

	return (sum);
}