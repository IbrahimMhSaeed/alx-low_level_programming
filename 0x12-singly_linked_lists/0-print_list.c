#include <stdio.h>
#include "lists.h"

/**
 * print_list - print linked list
 * @h: pointer for list header
 * Return: number of nodes in list
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *curr = h;

	if (h == NULL)
		return (0);

	while (curr != NULL)
	{
		if (curr->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", curr->len, curr->str);
		curr = curr->next;
		count++;
	}


	return (count);
}
