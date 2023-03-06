include "main.h"

/**_memcpy: copies content
 * @dest: memory area, destination
 * @src: memory area, source
 * @n: size
 * @i: array index
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	for(i = 0; n > 0; n--; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
