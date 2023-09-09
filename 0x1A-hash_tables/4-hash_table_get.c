#include "hash_tables.h"
/**
 * hash_table_get -This is responsible for retrieving a value associated with a key.
 * @ht: this isthe hash table you want to look into
 * @key: it's the key you are looking for
 * Return:This returns the value associated with key if found, NULL if failed
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{

hash_node_t *node;
unsigned long int index;

if (ht == NULL)
	return (NULL);

index = key_index((const unsigned char *) key, ht->size);
node = ht->array[index];

while (node != NULL)
{
	if (strcmp(node->key, key) == 0)
		return (node->value);

	node = node->next;
}
return (NULL);
}
