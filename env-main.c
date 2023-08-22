#include "shell.h"
/**
 * _getenv - return the string
 * @name: traited variable
 * Return: string or NULL
 */

char *_getenv(const char *name)
{
	char *S;
	extern char **environ;
	int i = 0;

	while (environ[i])
	{
		S = strtok(environ[i], "=");

		if (our_strcmp(name, S) == 0)
		{
			return (strtok(NULL, "\n"));
		}
		i++;
	}
	return (NULL);
}
