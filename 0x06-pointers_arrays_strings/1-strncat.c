#include "main.h"

/**
 * _strncat: concatenates two strings a character at a time
 * @i: tracks the length of the string pointed to by src
 * @j: tracks the length of the string pointed to by dest
 * Return: the pointer dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
		j++;
	}

	i = 0;

	while (*(src + i)  != '\0' && i < n )
        {
		dest[j] = src[i];
		i++;
                j++;
        }
	dest[j] = '\0';
	return (dest);
}
