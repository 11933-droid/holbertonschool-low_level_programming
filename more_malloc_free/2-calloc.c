#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _calloc - allocate memory
 * @nmemb: number of array
 * @size: size of array
 *
 * Return: pointer to array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	size_t total;
	unsigned char *p;
	size_t i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = (size_t)nmemb * (size_t)size;

	p = (unsigned char *)malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;
	return ((void *)p);
}
