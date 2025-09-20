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
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = (size_t)nmemb * (size_t)size;

	p = malloc(total);
	if (p == NULL)
		return (NULL);

	memset(p, 0, total);
	return (p);
}
