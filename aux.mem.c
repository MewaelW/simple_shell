#include "main.h"

/**
 * _memcpy -This function copies information between two void pointers
 *
 * @newptr: new pointer
 * @ptr: first pointer
 * @size: size of new pointer
 * Return: none
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *ptr_c = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int a;

	for (a = 0; a < size; a++)
		char_newptr[a] = ptr_c[a];
}

/**
 * _realloc - is a function that reallocates a memory block
 *
 * @ptr: pointer to previously allocated memory
 * @old_size: size of allocated space of ptr
 * @new_size: new size of new memory block
 * Return: ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newp;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newp = malloc(new_size);
	if (newp == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newp, ptr, new_size);
	else
		_memcpy(newp, ptr, old_size);

	free(ptr);
	return (newp);
}

/**
 * _reallocdp -This function reallocates a memory block of  double pointers
 *
 * @ptr: double pointer
 * @old_size: size of allocated space of ptr
 * @new_size: new size of the new memory block
 * Return: ptr or NULL
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newp;
	unsigned int a;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newp = malloc(sizeof(char *) * new_size);
	if (newp == NULL)
		return (NULL);

	for (a = 0; a < old_size; a++)
		newp[a] = ptr[a];

	free(ptr);

	return (newp);
}
