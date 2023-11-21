#include "lists.h"

/**
 * print_listint - print list
 * @h: pointer to head
 * Return: size_t integer
 */

size_t print_listint(const listint_t *h)
{

	size_t count = 0;

	while (h)
	{
		count++;
		printf("%lu\n", count);
		h = h->next;
	}

	return count;


}
