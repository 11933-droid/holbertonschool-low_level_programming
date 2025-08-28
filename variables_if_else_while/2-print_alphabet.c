#include <stdio.h>

/**
 * main - main function putchar
 *
 * Return: Always 0 (Succsess)
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		putchar(c);
	putchar('\n');
	return (0);
}
