#include "lists.h"

/**
 * free_dlistint - free dlist
 * @head: header of dlist
 * Return: None
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
