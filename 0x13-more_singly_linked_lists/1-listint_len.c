#include "lists.h"

/**
 * listint_len - print list of numbers
 * @h: pointer to head of list
 * Return: size_t integer returned
 */

size_t listint_len(const listint_t *h)
{

	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
