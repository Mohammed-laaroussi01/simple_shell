#include "shell.h"
/**
 * analze_cmd - Analyze line command
 * @input:User Input To analze
 * Return: Array Of Char analazed
 */

char **analze_cmd(char *input)
{
	char **tokens = NULL;
	char *token;
	int i = 0;

	if (input == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * BUFSIZE);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
	token = strtok(input, "\n ");
	while (token)
	{
	tokens[i++] = token;
	if (i >= BUFSIZE)
	{
		perror("hsh: Too many tokens");
		free(tokens);
		return (NULL);
	}
	token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
