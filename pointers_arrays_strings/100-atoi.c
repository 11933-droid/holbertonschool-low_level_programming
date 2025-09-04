#include "main.h"

/**
 * _atoi - convert a string to integer
 * @s: string to convert
 *
 * Return: the integer value, or 0
 */

int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			break;
		}
		else if (started)
			break;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';
		if (sign > 0)
			res = res * 10 + d;
		else
			res = res * 10 - d;
		i++;
		started = 1;
	}
	if (!started)
		return (0);
	return (res);
}
