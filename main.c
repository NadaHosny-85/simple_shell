#include "main.h"

/**
 * main - entry point
 *
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: 0 on success, 1 otherwise
 */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char *av[])
{
	char **argv = NULL;
	char *command = NULL;
	int i = 0;
	size_t len = 0;
	char *delim = " ;";
	int shell_interactive = 0;

	signal(SIGINT, SIG_IGN);
	shell_interactive = isatty(STDIN_FILENO);
	if (shell_interactive == 0)
	{
		i = _getline(&command, &len, stdin);
		while (i != EOF)
		{
			argv = toklist(command, delim);
			_executer(argv);
			command = NULL;
		}
		free(command);
		return (0);
	}
	while (i != EOF && shell_interactive)
	{
		write(1, "($) ", 4);
		i = _getline(&command, &len, stdin);
		if (i == EOF)
			exit(0);
		argv = toklist(command, delim);
		_executer(argv);
		free(command);
	}

	return (0);
}
