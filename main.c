#include "main.h"

/**
 * main - entry point
 *
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: 0 on success, 1 otherwise
 */

int main(ac, **av)
{
	int shell_interactivity;
	char *str = NULL;
	size_t len = 0;
	int i = 0;
	char **args;

	(void)av;

	signal(SIGINT, SIG_IGN);
	shell_interactivity = isatty(STDIN_FILENO);
	if (shell_interactivity == 0 && ac == 1)
	{
		i = _getline(&str, &len, stdin);
		while (i > 0)
		{
			char **args = toklist(str, " ");

			_executer(args);
			str = NULL;
		}
		free(str);
		return (0);
	}
	while (shell_interactivity)
	{
		write(1, "($) ", 4);
		i = _getline(&str, &len, stdin);
		while (i < 0)
		{
			free(str);
			write(1, "\n", 1);
			break;
		}
		char **args = toklist(str, " ");

		_executer(args);
		str = NULL;
	}
	return (0);
}
