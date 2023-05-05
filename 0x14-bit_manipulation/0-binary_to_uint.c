#include "main.h"

/**
 * binary_to_uint: converts a binary number to an unsigned int.
 * @b:pointer to the  string of binary symbols
 * Return: converted, 0 if one char is neither '0' or '1' or b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	unsigned int log;
	int length;

	if (b)
		for (length = 0; b[length]; length++)
		{
			if (b[length] != '0' && b[length] != '1')
				return (0);
		}
	else
		return (0);
	for (log = 1, num = 0, length--; length >= 0; length--, log *= 2)
	{
		if (b[length] == '1')
			num += log;
	}

	return (num);
}
