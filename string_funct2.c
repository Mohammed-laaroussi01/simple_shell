#include "shell.h"
/**
 * our_strtok - Parses a string into tokens,
 *              using a set of delimiters. This function maintains
 * state across multiple calls,
 *              allowing for successive tokenization of the same string.
 *
 * @str: The input string to tokenize.
 * @dl : A string containing delimiter characters.
 * Return : A pointer stat to the next token,
 *              or (NULL) if there are no more tokens or an error occurs.
 */
char *our_strtok(char *str, const char *dl)
{
	char *beg;
	static char *token;

	if (str)
		token = str;

	if (!token)
	{
		return (NULL);
	}

	beg = token;

	token = strpbrk(token, dl);

	if (token)
	{
		*token = '\0';
		token++;
	}

	return (beg);
}
