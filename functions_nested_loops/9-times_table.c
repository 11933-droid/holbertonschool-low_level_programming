#include "main.h"

/**
 * time_table - prints the 9 times
 *
 * Return: void
 */

void time_table(void)
{
	int r, c, p;

	for (r = 0; r <= 9; r++)
	{
		for (c = 0; c <= 9; c++)
		{
			p = r * c;

			if (c == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 10)
				{
					_putchar(' ');
					_putchar(p + '0');
				}
				else
				{
					_putchar((p / 10) + '0');
					_putchar((p % 10) + '0');
				}
			}
		}
		_putchar('\n');
	}
}
