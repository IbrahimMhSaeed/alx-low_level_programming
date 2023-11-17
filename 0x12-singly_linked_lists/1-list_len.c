#include <stdio.h>
#include "lists.h"

/**
 * list_len - count list element
 * @h: pointer for list header
 * Return: number of nodes in list
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;
	const list_t *curr = h;

	if (h == NULL)
		return (0);

	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}


	return (count);
}
