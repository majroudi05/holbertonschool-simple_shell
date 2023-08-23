#include"shell.h"
/**
*main - main shell program
*Return: nothing
*
*
**/
int main(void)
{
char *command;
while (1)
{
command = readline("$ ");
if (!command)
{
printf("\n");
break;
}
if (command[0] != '\0')
{
add_history(command);
}
printf("You entered: %s\n", command);
free(command);
}
return (0);
}
