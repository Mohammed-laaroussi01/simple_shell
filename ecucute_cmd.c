#include"shell.h"


void execute_command(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{

		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
			}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

