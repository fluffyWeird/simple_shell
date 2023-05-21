#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated with a call
 * to malloc: malloc(old_size).
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The size, in bytes, of the memory block.
 *
 * Return: If new_size == old_size, just return ptr. If new_size is equal
 * to zero, and ptr is not NULL, then the call is equivalent
 * to free(ptr). Return NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *N_ptr, *ptr_c;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		N_ptr = malloc(new_size);
		if (N_ptr == NULL)
			return (NULL);
		return (N_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_c = ptr;
	N_ptr = malloc(sizeof(*ptr_c) * new_size);
	if (N_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		N_ptr[i] = ptr_c[i];
	}
	free(ptr);
	return (N_ptr);
}
