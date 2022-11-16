#include "main.h"

/**
 * _realloc - function re allocates new space
 * in the memory
 *
 *
 * @ptr: pointer to the variable that needs to be
 * re-allocated
 * @cursize: current size of the variable
 * @newsize: new size of the variable
 *
 * Return: a pointer to the newly allocated var
 */
void *_realloc(void *ptr, unsigned int cursize, unsigned int newsize)
{
	void *tempptr;

	unsigned int i;

	unsigned int min = cursize > newsize ? cursize : newsize;

	if (newsize == cursize)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		ptr = malloc(newsize);
		return (ptr);
	}
	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}
	tempptr = malloc(newsize);
	if (tempptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < min; i++)
	{
		*((char *)tempptr + i) = *((char *)ptr + i);
	}
	free(ptr);
	return (tempptr);
}
