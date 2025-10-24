#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: pointer to the hash table
 *
 * Description: Prints key/value pairs in the order they appear in
 * the hash table array. Format: {'key1': 'value1', 'key2': 'value2', ...}
 * If ht is NULL, the function does nothing.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first_pair = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first_pair)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first_pair = 0;
			node = node->next;
		}
	}
	printf("}\n");
}
