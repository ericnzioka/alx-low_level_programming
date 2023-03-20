#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @print_dog: prints 'struct dog
 * * @dog: struct
 * @d: pointer
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		printf("");
	}
	else
	{
		if (d->name != NULL)
			printf("Name: %s\n", d->name);
		else
			printf("Name: (nil)\n");
		if (d->age >= 0)
			printf("Age: %.6f\n", d->age);
		else
			printf("Age: (nil)\n");
		if (d->owner != NULL)
			printf("Owner: %s\n", d->owner);
		else
			printf("Owner: (nil)\n");
	}
}
