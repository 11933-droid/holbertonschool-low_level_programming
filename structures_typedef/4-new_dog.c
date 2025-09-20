#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - compute length of a string
 * @s: string
 * Return: length (0 if s is NULL)
 */
static int _strlen(char *s)
{
	int n = 0;

	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

/**
 * _strdup - duplicate a string using malloc
 * @s: string to duplicate
 * Return: pointer to new string, or NULL on failure (or if s is NULL)
 */
static char *_strdup(char *s)
{
	int i, len;
	char *p;

	if (!s)
		return (NULL);
	len = _strlen(s);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	for (i = 0; i < len; i++)
		p[i] = s[i];
	p[len] = '\0';
	return (p);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name (copied)
 * @age: dog's age
 * @owner: owner's name (copied)
 * Return: pointer to new dog, or NULL if any allocation fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d = malloc(sizeof(*d));

	if (!d)
		return (NULL);

	d->name = _strdup(name);
	if (name && !d->name)
	{	free(d);
		return (NULL);
	}

	d->owner = _strdup(owner);
	if (owner && !d->owner)
	{	free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;
	return (d);
}

