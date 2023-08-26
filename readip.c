#include"shell.h"
/*
 * read_input: it read user input
 * Return: a pointer char
 */


char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	ssize_t len = getline(&input, &bufsize, stdin);


	if (len == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if (input[len - 1] == '\n')
	{
		input[len - 1] = '\0';
	}

	return (input);
}

