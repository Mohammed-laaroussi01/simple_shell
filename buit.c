#include "shell.h"
/**
 * his - Display History Of User Input Simple Shell
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */

int his(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	FILE *fp = fopen(".simple_shell_history", "r");
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er = NULL;

	if (fp == NULL)
	{
		return (-1);
	}

	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		sprintf(er, "%d", counter);
		printf("%s ", er);
		free(er);
		printf("%s", line);
	}

	if (line)
	{
		free(line);
	}

	fclose(fp);
	return (0);
}

/**
 * dis_echo - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */

int dis_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		{
			return (1);
		}
	}
}
