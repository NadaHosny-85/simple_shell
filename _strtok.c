#include "main.h"

/**
 * _strtok - loop through string and extract every word on it
 * takes delim string as seperator between words
 * @str: current string to extract tokens from
 * @delim: seperator between each word of the string
 * @backup: string that save the value of the remaing string
 * after delimeter
 * Return: the current string that has delim after it
 */

char *_strtok(char *str, char *delim, char **backup)
{
	char *returned_str;

	if (str == NULL)
		str = *backup;
	if (*str == '\0')
	{
		*backup = str;
		return (NULL);
	}

	str += _strspn(str, delim);

	if (*str == '\0')
	{
		*backup = str;
		return (NULL);
	}

	returned_str = str + _strcspn(str, delim);

	if (*returned_str == '\0')
	{
		*backup = returned_str;
		return (str);
	}

	*returned_str = '\0';
	*backup = returned_str + 1;
	return (str);
}

/**
 * _strcspn - get the number of chars in s1 that doesn't found in s2
 * @s1: string to get its chars
 * @s2: delimeters chars to stop counting at
 * Return: number of chars that are not in s2
 */

int _strcspn(char *s1, char *s2)
{
	int i = 0;
	int len = 0;

	while (s1[i] != '\0')
	{
		if (_strchr(s2, s1[i]) != NULL)
			break;
		i++;
		len++;
	}

	return (len);
}
