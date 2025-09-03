#include "main.h"

/**
 * swap_int - swaps to int
 * @a: poiner to first int
 * @b: pointer to second int
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
