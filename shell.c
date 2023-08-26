#include "shell.h"

/**
 * our_envi - Creat Array of Envi Vari
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void our_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = our_strdup(environ[i]);
	envi[i] = NULL;
}
/**
 * main - Simple Shell
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(void)
{
	char *input;
	char **cmd;
	int counter = 0, statue = 1;

	while (statue)
	{
	counter++;

	prompt();
	input = read_input();
	cmd = analze_cmd(input);

	if (input[0] == '\0')
	{
	continue;
	}

	cmd = analze_cmd(input);

	if (strcmp(cmd[0], "exit") == 0)
	{
	break;
	}
	else if (our_builtin(cmd) == 0)
	{
	statue = 0;
	}
	else
	{
		execute_command(cmd);
	}
	free(input);
	free(cmd);
	}

	return (statue);
}
/**
 * our_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int our_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i;

	if (*cmd == NULL)
	{
		return (-1);
	}

	for (i = 0; fun[i].command != NULL; i++)
	{
		if (our_strcmp(cmd[0], fun[i].command) == 0)
		{
			return (0);
		}
	}

	return (-1);
}
