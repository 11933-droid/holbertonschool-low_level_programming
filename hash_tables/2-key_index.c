#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: the key (string)
 * @size: size of array
 *
 * Return: the index where the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
