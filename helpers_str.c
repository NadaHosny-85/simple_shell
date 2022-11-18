#include "main.h"

/**
 * _strcpy - copy string from src to dest and return dest
 * @dest: string to copy to
 * @src: string to copy from
 * Return: dest string after copying the contents of src into it
 */

void _strcpy(char *src, char *dest)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

/**
 * _strlen - get string length
 * @dest: string to get its length
 * Return: number of chars in string
 */

int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len])
		len++;

	return (len);
}

/**
 * _strcat - concate src with dest and return dest string
 * @dest: string to concate to
 * @src: string to be added to dest
 * Return: dest string after concatinating src to
 */

char *_strcat(char *dest, char *src)
{
	char *new_string = NULL;
	int destlen = _strlen(dest);
	int srclen = _strlen(src);

	new_string = malloc(sizeof(*new_string) * (destlen + srclen + 1));
	_strcpy(dest, new_string);
	_strcpy(src, new_string + destlen);
	new_string[destlen + srclen] = '\0';
	return new_string;
}

/**
 * _strspn - find the first occurence of str2 in str1
 * @str2: string to search on
 * @str1: string to search for
 * Return: number of bytes that matched in both string
 */

int _strspn(char *s1, char *s2)
{
	int i = 0;
	int match = 0;

	for (; s1[i] != '\0'; i++)
	{
		if (_strchr(s2, s1[i]) == NULL)
			break;
		i++;
		match++;
	}

	return match;
}

/**
 * _strchr - get the place of char c from a string str
 * @str: string to search on
 * @c: char to search for
 * Return: pointer to the first occurance of charchater c
 */

char *_strchr(char *str, char c)
{
	int i = 0;

	for (; str[i] != c && str[i] != '\0'; i++)
		;

	if (str[i] == c)
		return str + i;
	else
		return NULL;
}