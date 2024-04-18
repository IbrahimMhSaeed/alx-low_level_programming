#include "hash_tables.h"


/**
 * hash_table_delete - delete a hash table
 * @ht: the hash table to be deleted
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	hash_node_t *del;

	if (!ht)
		return;
	if (!(ht->array))
		return;
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			free_item(del);
		}
	}
	free(ht->array);
	free(ht);
}
