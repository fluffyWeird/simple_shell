#include <string.h>
#include <stdio.h>
#include "main.h"


/**
 * path_dir_list - builds a linked list of the PATH directories.
 */
void path_dir_list(void)
{
	char *path, *dir;
	list_t *head;

	head = NULL;
	path = _getenv("PATH");
	if (path == NULL)
		return;

	dir = strtok(path, ":");
	if (dir == NULL)
		return;

	while (dir)
	{
		add_node_end(&head, dir);
		dir = strtok(NULL, ":");
	}
	print_list(head);
}
