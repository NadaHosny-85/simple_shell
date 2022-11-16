#include "main.h"

/**
 * _executer - execute commands passed to our shell
 * @args: number of arguments passed to our shell
 * Return: 1 on success
 */

int _executer(char **args)
{
	pid_t process;
	int status = 0;

	process = fork();

	if (process == -1)
	{
		perror("Error: Failed to Create Process");
		exit(EXIT_FAILURE);
	}
	if (process == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error: Falied to execute commands");
		}
		exit(EXIT_FAILURE);
	}
	if (process > 0)
	{
		wait(&status);
	}
	return (1);
}