#include "main.h"

/**
 * _sqrt_check - helper function
 * @n: number
 * @g: current guess
 *
 * Return: square root
 */

int _sqrt_check(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (_sqrt_check(n, g + 1));
}

/**
 * _sqrt_recursion - return natural square
 * @n: number to compute
 *
 * Return: natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (_sqrt_check(n, 1));
}
