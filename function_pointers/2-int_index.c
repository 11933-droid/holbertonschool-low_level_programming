#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - search for integer
 * @array: array
 * @size: size of array
 * @cmp: function pointer
 * return: index of matches
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) == 1)
				return (i);
	}
	return (-1);
}
