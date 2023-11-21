#include "lists.h"

/**
 * pop_listint - print list of numbers
 * @head: pointer to head of list
 * Return: vlaue of poped element
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (*head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = (*head)->next;

	free(temp);

	return (n);
}
