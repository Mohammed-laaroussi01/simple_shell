#include "shell.h"
/*
 * split_string - function of delimrtres
 * @buf: a pointer to char
 * @dl: a poiter to char
 * Rturn: a string
 */

char **split_string(char *buf, char *dl)
{
	char **tok;
	char *token;
	int i = 0;

	tok = malloc(sizeof(char *) * 1024);
	if (tok == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = our_strtok(buf, dl);
	while (token)
	{
		tok[i] = strdup(token);
		if (tok[i] == NULL)
		{
			exit(EXIT_FAILURE);
		}
		token = our_strtok(NULL, dl);
		i++;
		}
		tok[i] = NULL;
		return (tok);
}
