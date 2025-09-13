#include "main.h"

/**
 * _sqrt_recursion - return natural square
 * @n: number to compute
 *
 * Return: natural square root
 */

int _sqrt_recursion(int n)
{
	static int g = 1;
	int result;

	if (n < 0)
		return (-1);
	if (g * g == n)
	{
		result = g;
		g = 1;
		return (result);
	}
	if (g * g > n)
	{
		g = 1;
		return (-1);
	}
	g++;
	return (_sqrt_recursion(n));
}
