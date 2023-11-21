#include "lists.h"

/**
 * free_listint2 - print list of numbers
 * @head: pointer to head of list
 */

void free_listint2(listint_t **head)
{
	listint_t *curr = *head;
	listint_t *next;

	while (curr)
	{
		next = curr;
		curr = curr->next;
		free(next);
	}

	*head = NULL;
}
