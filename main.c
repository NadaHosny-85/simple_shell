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
	char **commands = NULL;
	char **argv = NULL;
	char *command = NULL;
	int i = 0;
	size_t len = 0;
	char *delim = " ;";
	int shell_interactive = 0;
	int j;

	signal(SIGINT, SIG_IGN);
	shell_interactive = isatty(STDIN_FILENO);
	if (shell_interactive == 0)
	{
		while ((i = getline(&command, &len, stdin)) != -1)
		{
			rmnewl(command);
			commands = toklist(command, "\n");
			for (j = 0; commands[j] != NULL; j++)
			{
				printf("%s\n", commands[j]);
				argv = toklist(commands[j], delim);
				if (argv[0] == NULL)
				{
					free(argv);
					break;
				}
				_executer(argv);
			}
			free(argv);
		}
		free(commands);
		return (0);
	}
	while (i != EOF && shell_interactive)
	{
		write(1, "($) ", 4);
		i = _getline(&command, &len, stdin);
		if (i == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		argv = toklist(command, delim);
		_executer(argv);
		free(argv[0]);
		free(argv);
	}

	return (0);
}
