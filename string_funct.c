#include "shell.h"

/**
 * our_strlen - Calculates the length of a null-terminated string.
 *
 * @str: The input string.
 * Return: The number of characters in the string,
 *		excluding the null-terminator.
 */
size_t our_strlen(const char *str)
{
	size_t len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}


/**
 * *our_strcat - Concatenates two strings and returns the result.
 *
 * @s1: The first string.
 * @s2: The second string to be appended to the first.
 * Return: A pointer to the new concatenated string, or NULL on error.
 */
char *our_strcat(const char *s1, const char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char *result = malloc(len1 + len2 + 1);

	if (!result)
		return (NULL);

	strcpy(result, s1);
	strcat(result, s2);

	return (result);
}

/**
 * our_strcmp - compares two character strings ( str1 and str2 )
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return : return value of function -strcmp-
 */
int our_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * *our_strncpy - Copies at most n characters from the source string
 *
 * @dest: The destination string to copy characters to.
 * @src : The source string to copy from.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the destination string dest.
 */
char *our_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * our_strcpy - Copies the source string src
 *		into the destination string dest.
 *		The function ensures that
 *		the destination string will be null-terminated.
 *
 * @dest: The destination string to copy characters to.
 * @src : The source string to copy from.
 * Return: A pointer to the destination string dest.
 */
char *our_strcpy(char *dest, const char *src)
{
	return (our_strncpy(dest, src, strlen(src) + 1));
}

