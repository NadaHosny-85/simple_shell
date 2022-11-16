#include "main.h"

/**
 * _getline - reads the command that user enters in the stdin
 * and return the number of chars written on that command
 * @buffer: a pointer to string
 * @len: a pointer to int represent the number of chars on the buffer
 * @stream: a file descriptor represent the stdin
 * Return: the number of charchters that user has input
 */

size_t _getline(char **buffer, size_t *len, FILE *stream)
{
	char *ptr;
	int c;

	if (*buffer == NULL && *len == 0)
	{
		*len = BUFSIZ;
		if ((*buffer = malloc(*len)) == NULL)
			return (-1);
	}

	ptr = *buffer;
	while (1)
	{
		c = fgetc(stream);
		if (c == -1)
		{
			if (feof(stream))
				return ((ptr == *buffer) ? -1 : ptr - *buffer);
			else
				return (-1);
		}
		if (c == '\n')
		{
			*ptr = '\0';
			return (ptr - *buffer);
		}
		*ptr++ = c;
	}
}
