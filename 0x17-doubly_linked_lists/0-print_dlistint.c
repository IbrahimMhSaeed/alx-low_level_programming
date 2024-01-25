#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - print dlist
 * @h: header of list
 * Return: list size
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count;

	if (h == NULL)
		return (0);
	count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
