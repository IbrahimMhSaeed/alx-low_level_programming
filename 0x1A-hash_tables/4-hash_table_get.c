#include "hash_tables.h"

/**
 * hash_table_get - get element from hash table
 * @ht: hash table to be searched
 * @key: key of element required
 * Return: value (Success) || NULL (fail)
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp;

	if (!ht)
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);
	if (!(ht->array[index]))
		/* Key not in hash table */
		return (NULL);

	/* Search for key */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			/* Key found return value */
			return (temp->value);
		}
		temp = temp->next;
	}

	/* key not found */
	return (NULL);
}
