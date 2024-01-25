#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: header of dlist
 * @index: index of node to be deleted
 * Return: always 1 (Success)
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h;
	dlistint_t *temp;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	h = *head;
	i = 0;
	while (h->next != NULL)
	{
		if (i == index)
		{
			temp = h;
			h->next->prev = h->prev;
			h->prev->next = h->next;
			free(temp);
			return (1);
		}
		i++;
		h = h->next;
	}
	if (i == index)
	{
		temp = h;
		h->prev->next = NULL;
		free(temp);
		return (1);
	}
	return (-1);
}
