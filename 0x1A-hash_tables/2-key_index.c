#include "hash_tables.h"

/**
 * key_index -this returns the index of a given key
 * @key:the key
 * @size:This indicates the size of the array of the hash table
 * Return:This returns index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
