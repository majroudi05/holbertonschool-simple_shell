#include"shell.h"
/**
 *tokenize - Split line into tokens
 * @input: input of user
 * Return: Array of tokens
 *
**/
char **tokenize(char *input)
{
	char **array[INPUT_LENGTH];
	char *token;
	int i = 0;

	token = strtok(input, " \n\t");
	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	array[i] = NULL;
	return (array);
}
