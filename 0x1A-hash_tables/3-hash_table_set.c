#include "hash_tables.h"

/**
 * hash_table_set - insert value into hash table
 * @ht: pointer to hash table
 * @key: key to be inserted
 * @value: value of key to be inserted
 * Return: always 1 (Success), (0 on Fail)
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *item;
	hash_node_t *temp;
	unsigned long int index;

	if (!ht || strcmp(key, "") == 0)
		return (0);
	/* Create item */
	item = malloc(sizeof(hash_node_t));
	if (!item)
		return (0);
	item->key = malloc(sizeof(char) * (strlen(key) + 1));
	item->value = malloc(sizeof(char) * (strlen(value) + 1));
	item->next = NULL;
	if (!item->key || !item->value)
	{
		free_item(item);
		return (0);
	}
	strcpy(item->key, key);
	strcpy(item->value, value);
	/* Generate index */
	index = key_index((unsigned char *) key, ht->size);
	if (!(ht->array[index]))
	{
		/* direct insertion */
		ht->array[index] = item;
	} else
	{
		temp = ht->array[index];
		while (temp != NULL)
		{
			if (strcmp(temp->key, key) == 0)
			{
				/* override value */
				free(temp->value);
				temp->value = malloc(sizeof(char) * (strlen(value) + 1));
				strcpy(temp->value, value);
				free_item(item);
				return (1);
			}
			temp = temp->next;
		}
		/* add to linked list */
		item->next = ht->array[index];
		ht->array[index] = item;
	}
	return (1);
}
