#include"shell.h"
/**
*main - Entry Function
*
*Return: 0 (on success)
*/
int main(void)
{
char input[INPUT_LENGTH];
pid_t child_pid;
char *args[INPUT_LENGTH];
har *token;
int i = 0;
while (1)
{
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
}
else if (child_pid == 0)
{
token = strtok(input, " ");
while (token != NULL)
{
args[i] = token;
i++;
token = strtok(NULL, " ");
}
args[i] = NULL;
exexve(args[0], args, NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(child_pid, &status, 0);
}
}
return (0);
}