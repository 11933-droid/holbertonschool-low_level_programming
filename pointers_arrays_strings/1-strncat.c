#include "main.h"

/**
 * _strncat - concatenates tow strings
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes
 *
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	char *d = dest;
	int i = 0;

	while (*d)
		d++;
	while (i < n && src[i] != '\0')
	{
		*d = src[i];
		d++;
		i++;
	}
	*d = '\0';
	return (dest);
}
