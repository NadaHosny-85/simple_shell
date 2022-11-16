#include "main.h"

/**
 * is_delim - check if string has any of charchters of the delims string
 * @delims: array of chars as string delimeters
 * @str: current string char
 * Return: 1 if any of chars in delims is equal to str char
 */

int is_delim(const char *delims, char str)
{
	int i;
	for (i = 0; delims[i]; i++)
	{
		if (str == *((char *)delims + i))
			return (1);
	}
	return (0);
}

/**
 * _strtok - loop through string and extract every word on it
 * takes delim string as seperator between words
 * @str: current string to extract tokens from
 * @delim: seperator between each word of the string
 * Return: the current string that has delim after it
 */

char *_strtok(char *str, const char *delim, char **backup)
{
	if (str == NULL)
		str = *backup;

	if (*str == '\0')
	{
		*backup = str;
		return NULL;
	}

	while (1)
	{
		if (is_delim(delim, *str))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		break;
	}

	char *returned_str = str;

	while (1)
	{
		if (is_delim(delim, *str))
		{
			*backup = str + 1;
			*str = '\0';
			return returned_str;
		}
		if (*str == '\0')
		{
			*backup = str;
			return returned_str;
		}
		str++;
	}

	return str;
}
