#include"shell.h"
/**
*main - The entry Function
*Return: nothing
**/
int main(void)
{
	char *input[INPUT_LENGTH];
	char token;
	size_t size = 0;

	while (1)
	{
		printf("$ >");
		if (getline(&input, &size, stdin) == -1)
		{
			break;
		}
		token = tokenize(input);
		execute(token);
		}
}
