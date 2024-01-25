#include "lists.h"

/**
 * get_dnodeint_at_index - get node at index
 * @head: header of dlist
 * @index: index to be searched
 * Return: node at specific index (Success) || NULL (Fail)
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	while (head != NULL)
	{
		if (i == index)
			return (head);
		i++;
		head = head->next;
	}

	return (NULL);
}
