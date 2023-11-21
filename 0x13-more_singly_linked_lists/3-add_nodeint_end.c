#include "lists.h"

/**
 * add_nodeint_end - print list of numbers
 * @head: pointer to head of list
 * @n: number integer
 * Return: size_t integer returned
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *node = malloc(sizeof(listint_t));
	listint_t *curr = *head;

	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (!head)
	{
		*head = node;
	} else
	{
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = node;
	}

	return (node);
}
