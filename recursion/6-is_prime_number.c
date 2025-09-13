#include "main.h"

/**
 * check_prime - helper function
 * @n: number to check
 * @d: current divisisor
 *
 * Return: 1 if prime, 0 otherwise
 */

int check_prime(int n, int d)
{
	if (d * d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (check_prime(n, d + 1));
}

/**
 * is_prime_number - checks if a number
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, 2));
}
