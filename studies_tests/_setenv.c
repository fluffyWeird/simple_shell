#include <stdio.h>
#include "main.h"

/**
 * _setenv - changes or adds an environment variable
 * @name: The name of enviroment variable to set.
 * @value: The value to set the name to.
 * @overwrite: An integer value that determines if the value should
 * be overwritten if non zero or otherwise
 * Return: 1 on success or -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **env, *new_list, *tvalue, *target;
	list_t *head;
	char *n;
	char *v;

	if (name == NULL || value == NULL)
		return (-1);

	n = _strdup(name);
	v = _strdup(value);
	if (n == NULL || v == NULL)
	{
		perror("_strdup");
		return (-1);
	}

	head = NULL;
	for (env = environ; *env; env++)
	{
		add_node_end(&head, *env);
	}

	if (_getenv(n) != NULL && overwrite == 1)
	{
		new_list = str_concat(n, "=");
		new_list = str_concat(new_list, v);
		tvalue = _getenv(n);
		if (tvalue == NULL)
			return (-1);

		target = str_concat(n, "=");
		target = str_concat(target, tvalue);
		delete_node(&head, target);
		add_node_end(&head, new_list);
	}
	else if (_getenv(n) != NULL && overwrite == 0)
	{
		print_list(head);
		return (1);
	}
	else
	{
		new_list = str_concat(n, "=");
		new_list = str_concat(new_list, v);
		add_node_end(&head, new_list);
	}

	print_list(head);

	free(n);
	free(v);
	return (1);
}
