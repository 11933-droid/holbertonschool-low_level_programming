#include "main.h"

/**
 * _strlen - return the lengh of string
 * @s: pointer to string
 *
 * Return: lengh of the string
 */

int _strlen(char *s)
{
	int i = 0;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);

}
