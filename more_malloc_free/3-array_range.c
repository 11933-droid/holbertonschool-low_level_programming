#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - create arrays
 * @min: minimum number
 * @max: maximum number
 *
 * Return: new allocated
 */

int *array_range(int min, int max)
{
	int i;
	int size;
	int *output;

	if (min > max)
		return (NULL);
	size = (max - min) + 1;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return (NULL);
	for (i = 0; min <= max; i++)
		output[i] = min++;
	return (output);
}
