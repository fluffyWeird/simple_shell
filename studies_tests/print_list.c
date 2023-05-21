#include <stdio.h>
#include "main.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: Head pointer.
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t count;

	count = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("(nil)\n");
			count++;
			h = h->next;
		}
		printf("%s\n", h->str);
		count++;
		h = h->next;
	}
	return (count);
}
