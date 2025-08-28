#include <stdio.h>

/**
 * main - Print alpha putchar
 *
 * Return: Always 0 (Succsess)
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		putchar(c);
	for (c = 'A'; c <= 'Z'; c++)
		putchar(c);
	putchar('\n');
	return (0);
}
