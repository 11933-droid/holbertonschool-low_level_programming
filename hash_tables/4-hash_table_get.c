#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieves the value associated with a key
 * @ht: pointer to the hash table
 * @key: the key to look for
 *
 * Return: pointer to the associated value, or NULL if key is not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	node = ht->array[idx];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
