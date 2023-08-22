#include "shell.h"
/*
 * _setenv - intialize a new envirroment variable,
 *		or modifu the prevouis
 * @nm: argument infos
 * @v: the string env var properly
 * @o: the string env var value
 * Return: Always 0
 */




int _setenv(const char *nm, const char *v, int o)
{
	int len = 0;
	int i = 0;
	char *var;

	if (!nm || !v)
		return (-1);
	while (environ[i])
	{
		len = our_strlen(nm);
		if (strncmp(environ[i], nm, len) == 0)
		{
			if (o)
			{
				var = malloc(len + 2 + our_strlen(v));
				our_strcpy(var, nm);
				our_strcat(var, "=");
				our_strcat(var, v);
				environ[i] = var;
				return (0);
			}
			return (0);
			}
		i++;
	}
	var = malloc(len + 2 + our_strlen(v));
	our_strcpy(var, nm);
	our_strcat(var, "=");
	our_strcat(var, v);
	environ[i] = var;
	environ[i + 1] = NULL;
	return (0);
}
