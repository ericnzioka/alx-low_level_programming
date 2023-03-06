#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 * consist only of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	int i;

	for (i = 0; accept[i] != '\0'; i++)
	{
		if (s[i] == accept[i])
			return (i);
	}
}
