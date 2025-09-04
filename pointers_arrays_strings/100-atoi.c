#include "main.h"

/**
 * _atoi - convert a string to integer
 * @s: string to convert
 *
 * Return: the integer value, or 0
 */

int _atoi(char *s)
{
	int i = 0;
       	int sign = 1;
       	int res = 0;
	int collecting = 0;

	while (s[i] != '\0')
	{
		if (!collecting && s[i] == '-')
			sign = -sign;
		else if (!collecting && s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int d = s[i] - '0';
			collecting = 1;
			if (sign == 1)
				res = res * 10 + d;
			else
				res = res * 10 - d;
		}
		else if (collecting)
			break;
		i++;
	}
	return (res);
}
