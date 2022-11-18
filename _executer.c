#include "main.h"

/**
 * _executer - execute commands passed to our shell
 * @args: number of arguments passed to our shell
 * Return: 1 on success
 */

int _executer(char **args)
{
	pid_t process;
	int status;

	process = fork();

	if (args == NULL)
		return (-1);

	if (process == -1)
	{
		perror("Error: Failed to Create Process");
		return (1);
	}
	if (process == 0)
	{
		if (execve(args[0], args, NULL) < 0)
		{
			perror("Error: Falied to execute commands");
			exit(-1);
		}
	}
	if (process > 0)
	{
		wait(&status);
	}
	return (1);
}
