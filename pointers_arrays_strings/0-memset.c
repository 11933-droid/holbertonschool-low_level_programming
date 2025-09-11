#include "main.h"

/**
 * _memset - fills memory
 * @s: area to fill with byet
 * @b: constant byet
 * @n: number of byet
 *
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
