#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * create_node - allocates and initializes a new hash table node
 * @key: key string (must be duplicated)
 * @value: value string (must be duplicated)
 *
 * Return: pointer to the new node, or NULL on failure
 */

static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - adds or updates a key
 * @ht: pointer to the hash table
 * @key: the key (must be a non-empty string)
 * @value: the value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node;
	char *value_dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node = ht->array[idx];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_dup = strdup(value);
			if (value_dup == NULL)
				return (0);
			free(node->value);
			node->value = value_dup;
			return (1);
		}
		node = node->next;
	}
	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
