#include "main.h"
#include <stdlib.h>

/**
 *_strdup- duplicates the string
 *@str: checked
 *
 *Return: array
 */

char *_strdup(char *str)
{
	char *duplicate;

	int i, len = 0;


	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; ++i)
		len++;

	duplicate = malloc(sizeof(char) * (len));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];

	duplicate[i+1] = '\0';

	return (duplicate);
}
