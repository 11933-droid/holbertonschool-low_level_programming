#include "main.h"

/**
 * _atoi - convert a string to integer
 * @s: string to convert
 *
 * Return: the integer value, or 0
 */

int _atoi(char *s)
{
	int i = 0, sign = 1, collecting = 0;
	int res = 0, d;

	while (s[i] != '\0')
	{
		if (!collecting && s[i] == '-')
			sign = -sign;
		else if (!collecting && s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		d = s[i] - '0';
		if (sign == 1)
			res = res * 10 + d;
		else
			res = res * 10 - d;
		i++;
		collecting = 1;
	}
	return (res);
}
