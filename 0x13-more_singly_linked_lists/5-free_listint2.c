#include "lists.h"

/**
 * free_listint2 - print list of numbers
 * @head: pointer to head of list
 */

void free_listint2(listint_t **head)
{
	listint_t *curr;

	while (*head != NULL)
	{
		curr = *head;
		*head = *head->next;
		free(curr);
	}

	*head = NULL;
}
