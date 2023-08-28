#include"shell.h"
void display_prompt(void)
{
printf("$");
fflush(stdout);
}
int main(void)
{
char input[INPUT_LENGTH];
while (1)
{
display_prompt();
if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}
input[strcspn(input, "\n")] = '\0';
pid_t child_pid = fork();
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
