#include "shell.h"
/**
 * get_command - returns the string
 * @cmd:command of user
 * Return: token or NULL
 */

char *get_command(char *cmd)
{
	char *all_cmd;
	char *path = _getenv("path");
	struct stat st;
	char *token;

	token = strtok(path, ":");
	while (token)
	{
		all_cmd = malloc(our_strlen(token) + our_strlen(cmd) + 2);
		our_strcpy(all_cmd, token);
		our_strcat(all_cmd, "/");
		our_strcat(all_cmd, cmd);
		if (stat(all_cmd, &st) == 0)
		{
			return (all_cmd);
		}
			free(all_cmd);
		token = our_strtok(NULL, ":");
	}
	return (NULL);
}
