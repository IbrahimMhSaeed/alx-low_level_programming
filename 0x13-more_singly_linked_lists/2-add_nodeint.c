#include "lists.h"

/**
 * add_nodeint - print list of numbers
 * @h: pointer to head of list
 * Return: size_t integer returned
 */

listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t *node = malloc(sizeof(listint_t));

	if (!node || !head)
		return (NULL);

	node->n = n;
	node->next = *head;
	*head = node;

	return (head);
}
