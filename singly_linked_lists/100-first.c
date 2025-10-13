#include <stdio.h>

/**
 * before_main - prints a quote before main is executed
 *
 * Return: nothing
 */

void __attribute__((constructor)) before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
