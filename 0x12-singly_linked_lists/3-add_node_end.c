#include "lists.h"

/**
 * add_node_end - count list element
 * @head: pointer for list header
 * @str: string to copy
 * Return: number of nodes in list
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node = malloc(sizeof(list_t));
	list_t *curr = head;

	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	node->len = strlen(str);

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = node;
	node->next = NULL;

	return (*node);
}
