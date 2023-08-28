#include"shell.h"
int main(void)
{
char input[INPUT_LENGTH];
pid_t child_pid;
int i;
while (1)
{
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';
if (strlen(input) >= 8 && input[0] == ' ' && input[strlen(input)-1] == ' ')
{
char command[INPUT_LENGTH];
snprintf(command, sizeof(command), "%s", input + 1); 
command[strlen(command) - 1] = '\0';
for (i = 0; i < 4; i++)
{
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
}
else if (child_pid == 0)
{
if (execlp(command, command, (char *)NULL) == -1)
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
} 
else
{
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
}
return (0);
}
