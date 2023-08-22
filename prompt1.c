#include "shell.h"
/*
 * main - print and execute the user command
 * @M : number of argument
 * @argv: arguments
 * @environ: variable enviarment
 * Return : always 0
 */
int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char *k;
	pid_t pid;
	int status, num_c;
	char **args;

	while (1)
	{
		write(1, "$ ", 2);
		num_c = getline(&buf, &buf_size, stdin);
		if (num_c == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		args = split_string(buf, " \t\n");
		if (our_strcmp(args[0], "exit") == 0)
			our_exit();
		pid = fork();
		if (pid == 0)
		{
			k = get_command(args[0]);
			if (k)
			{
				execve(k, args, environ);
			}
			else{
				printf("command not found\n");
				exit(0);
			}
		}
		else{
			wait(&status);
		}
	}
	return (0);
}
