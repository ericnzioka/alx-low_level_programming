#include "main.h"

/**
 * get_endianness - checks for endianness
 * Return: 0 for big endien, 1 for little endien
 */
int get_endianness(void)
{
	unsigned int j;
	char *k;

	j = 1;
	*k = (char *) &j;
	return (*k);
}
