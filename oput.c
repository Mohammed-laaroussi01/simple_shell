#include"shell.h"
/**
 *  our_prerror - Print Error
 * @argv: Program Name
 * @c: Error
 * @cmd: Command
 * Return: Void
 */
void our_prerror(char **argv, int c, char **cmd)
{
	char *Error = malloc(1024);

	if (Error == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
        }


	sprintf(Error, "%d", c);


	printf("%s: %s: %s: Illegal number: %s\n", argv[0], Error, cmd[0], cmd[1]);

	free(Error);
}

