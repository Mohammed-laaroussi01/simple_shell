#include "shell.h"
/**
 * our_strtok - Token A String Into Token (strtrok)
 * @str: String
 * @dl: Delimiter
 * Return: Pointer To The Next Token Or NULL
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
/**
 * our_strchr - Locate Charactere In Str
 * @str:String looking for In char
 * @character:Char To Search For
 * Return: Pointer To Char*
 */

char *our_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
	if (*str == character)
	{
		return ((char *)str);
	}
	str++;
	}
	if (character == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 * our_strdup - Duplicate A Str
 * @src:String
 * Return: Duplicate String Failed Null
 */

char *our_strdup(const char *src)
{
	size_t len = strlen(src) + 1;
	char *dest = malloc(len);

	if (dest != NULL)
	{
		our_strcpy(dest, src);
	}

	return (dest);
}
