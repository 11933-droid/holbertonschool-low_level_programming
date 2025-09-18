#include "main.h"

/**
 * *create_array - creat arrays of char
 * @size: size of arrays
 * @c: char to initialize
 *
 * Return: pointer to the arrays
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
		return (NULL);

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;
	return (arr);
}
