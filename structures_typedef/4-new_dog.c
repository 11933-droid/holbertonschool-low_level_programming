#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
	* new_dog - creates a new dog
	* @name: name of the dog
	* @age: age of the dog
	* @owner: name of the owner
	*
	* Return: pointer to new dog, or NULL if fail
	*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *new_name, *new_owner;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
	return (NULL);

	/* copy name */
	if (name != NULL)
	{
	new_name = malloc(strlen(name) + 1);
	if (new_name == NULL)
	{
	    free(d);
	    return (NULL);
	}
	strcpy(new_name, name);
	}
	else
	{
	new_name = NULL;
	}

	/* copy owner */
	if (owner != NULL)
	{
	new_owner = malloc(strlen(owner) + 1);
	if (new_owner == NULL)
	{
	    free(new_name);
	    free(d);
	    return (NULL);
	}
	strcpy(new_owner, owner);
	}
	else
	{
	new_owner = NULL;
	}

	d->name = new_name;
	d->age = age;
	d->owner = new_owner;
	return (d);
}
