#include "lists.h"

/**
 * insert_dnodeint_at_index - insert node at specific index
 * @h: head of dlist
 * @idx: index to insert at
 * @n: value to be inserted
 * Return: address of new node (Success) || NULL (Fail)
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *temp;
	unsigned int i;

	if (idx == 0)
	{
		new = add_dnodeint(h, n);
		return (new);
	}

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	i = 0;
	temp = *h;
	new->n = n;
	while (temp != NULL)
	{
		if (i == idx)
		{
			new->next = temp;
			temp->prev->next = new;
			new->prev = temp->prev;
			temp->prev = new;
			return (new);
		}
		i++;
		temp = temp->next;
	}
	if (i == idx)
	{
		free(new);
		new = add_dnodeint_end(h, n);
		return (new);
	}
	return (NULL);
}
