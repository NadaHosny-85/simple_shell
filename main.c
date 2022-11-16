#include "main.h"

/**
 * main - entry point
 * Return: 0 on success, 1 otherwise
 */

int main(void)
{
	char *str;
	size_t len;
	int i = 0;

	while (i != -1)
	{
		i = _getline(&str, &len, stdin);

		char **args = toklist(str, " ");

		_executer(args);
	}

	return (0);
}
