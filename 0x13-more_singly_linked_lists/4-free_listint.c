#include "lists.h"

/**
 * free_listint - print list of numbers
 * @head: pointer to head of list
 * Return: Void
 */

void free_listint(listint_t *head)
{
	listint_t *curr;

	if (!head)
		return ;

	while (head)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}
