#include"shell.h"
int main(void)
{
char input[INPUT_LENGTH];
pid_t child_pid;
while (1)
{
if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}
input[strcspn(input] = '\0';
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
}
else if (child_pid == 0)
{
if (execlp(input, input, (char *)NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(child_pid, &status, 0);
}
}
return (0);
}
