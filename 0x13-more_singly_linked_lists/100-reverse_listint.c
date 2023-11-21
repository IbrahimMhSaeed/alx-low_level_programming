#include "lists.h"

/**
 * reverse_listint - print list of numbers
 * @head: pointer to head of list
 * Return: node at specified index
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *forward;

	if (*head == NULL)
		return (NULL);


	while (*head != NULL)
	{
		forward = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		if (!forward)
			break;

		*head = forward;

	}

	return (*head);
}
