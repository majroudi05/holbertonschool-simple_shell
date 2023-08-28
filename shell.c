#include"shell.h"
void strtrim(char *str)
{
while (*str && isspace(*str))
{
str++;
}
if (*str == '\0')
{
return;
}
char *end = str + strlen(str) - 1;
while (end > str && isspace(*end))
{
end--;
}
*(end + 1) = '\0';
}
int main(void)
{
char input[INPUT_LENGTH];
pid_t child_pid;
while (1)
{
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
strtrim(input);
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
