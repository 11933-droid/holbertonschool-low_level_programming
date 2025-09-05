#include "main.h"

/**
 * _strcat - concatenates tow strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	char *d = dest;

	while (*d)
		d++;

	while (*src)
	{
		*d = *src;
		d++;
		src++;
	}
	*d = '\0';
	return (dest);
}
