#include "main.h"

/**
 * get_endianness- a function that checks the endianness
 * Return: 1 if success, 0 otherwise
 */

int get_endianness(void)
{
	unsigned int see = 1;
	char *order = (char *)&see;

	if (*order)
		return (1);
	return (0);
}
