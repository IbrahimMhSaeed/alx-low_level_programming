#include "hash_tables.h"

/**
 * print_list - print the list
 * @item: head of list
 * @flag: to control format of printing
 * Return: flag value for print template
 */

int print_list(hash_node_t *item, int flag)
{
	hash_node_t *temp;

	temp = item;
	if (!item)
		return (flag);
	while (temp != NULL)
	{
		if (flag == 1)
		{
			printf("\'%s\': \'%s\'", temp->key, temp->value);
			flag = 0;
		} else
		{
			printf(", \'%s\': \'%s\'", temp->key, temp->value);
		}
		temp = temp->next;
	}
	return (flag);
}

/**
 * hash_table_print - prints a hash table
 * @ht: pointer to the hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int flag;

	flag = 1;
	if (!ht)
		return;
	/*check if array is null*/
	if (!ht->array)
	{
		printf("{}\n");
		return;
	}
	/*Go through array indexes (ht->size)*/
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		flag = print_list(ht->array[i], flag);
	}
	printf("}\n");
}
