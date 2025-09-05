#include "main.h"

/**
 * _strncpy - copy at most n bytes
 * @dest: destination buffer
 * @src: source string
 * @n: max number of bytes
 *
 * Return: pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
