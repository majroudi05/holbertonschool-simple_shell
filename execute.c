#include"shell.h"
/**
 *execute - Function that create teh child process ID
 *@token: Iput token
 *Return: -1 or 0 or positive value
 *
**/
int execute(char *token)
{
	pid_t pid;
	int exc;
	char *path;
	char *args[INPUT_LENGTH];

	pid = fork();

	if (pid == -1)
	{
		perror("error");
		return (-1);
	}
	else if (pid == 0)
	{
		exc = execve(path, args, NULL);
	}
	else
	{
		wait(NULL);
	}
return (exc);
}
