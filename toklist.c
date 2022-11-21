#include "main.h"

/**
 * toklist - function creates an array of tokens
 *
 * @command: string which represents arguments which will
 * be passed to the program
 * @delim: the delimeter that you need to break string
 *
 * Return: pointer to the first element in the array
 */
char **toklist(char *command, char *delim)
{
	int count = 0;
	char **argv = NULL;
	// char *bstr = NULL;
	char *token = NULL;

	token = strtok(command, delim);

	while (token != NULL)
	{
		argv = _realloc(argv, sizeof(*argv) * (count), sizeof(*argv) * (count + 1));
		if (argv == NULL)
		{
			perror("Error: Allocation Error\n");
			exit(EXIT_FAILURE);
		}
		argv[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	// free(command);
	free(token);
	argv = _realloc(argv, sizeof(*argv) * (count), sizeof(*argv) * (count + 1));
	argv[count] = NULL;
	return (argv);
}
