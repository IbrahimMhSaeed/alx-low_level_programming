#include "lists.h"

/**
 * free_list - count list element
 * @head: pointer for list header
 * Return: void
 */

void free_list(list_t *head)
{

	list_t *next, *curr;

	if (head == NULL)
		return;

	next = head->next;

	free(head->str);
	free(head);

	while (next != NULL)
	{
		curr = next;
		next = curr->next;
		free(curr->str);
		free(curr);
	}

	return;

}
