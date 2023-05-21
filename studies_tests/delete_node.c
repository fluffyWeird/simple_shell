#include "main.h"

/**
 * delete_nodeint_at_index - deletes a node
 * of a list_t linked list.
 * @head: The pointer to the head pointer
 * @key: The data stored at the node to be deleted.
 */
void delete_node(list_t **head, char *key)
{
	list_t *previous = NULL;
	list_t *current;

	if (*head == NULL)
		return;

	current = *head;
	if (current != NULL && current->str == key)
	{
		*head = (current)->next;
		free(current);
		return;
	}

	while (current != NULL && current->str != key)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return;

	previous->next = current->next;
	free(current);
}
