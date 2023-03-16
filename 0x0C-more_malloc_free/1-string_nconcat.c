#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat: concates two strings
 * @*s1: string one
 * @*s2: pointer to string two
 * @n: first n bytes of s2
 * @m: new memory
 * @i: iteration index
 * @len1: length of s1
 * @len2: length of s2
 * @len: length s1 + s2
 * Return: m if succes, if fail return NULL 
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *m;
	unsigned int i;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int len;

	while(s1[len1] != '\0')
	{
		len1++;
	}
	while(s2[len2] != '\0')
	{
		len2++;
	}
	len = len2 + len1 + 1;
	m = malloc(len);
	for(i = 0; i < len1; i++)
	{
		m[i] = s1[i];
	}	
	if (n >= len2)
	{
		for(i = len1; i < len; i++)
		{
			m[i] = s2[i-len1];
		}
	}
	if(n < len2)
	{
		n = n + len1;
		for(i = len1; i < n; i++)
                {
                	m[i] = s2[i-len1];
		}
	}
	m[i] = '\0';

	if (m == NULL)
		return (NULL);
	return (m);
}
