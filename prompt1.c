#include "shell.h"
/**
 * print_error - Display Error
 * @input:User Input
 * @counter:Simple Shell Count
 * @argv:Program Name
 * Return: Void
 */


void print_error(char *input, int counter, char **argv)
{
	char er[12];

	write(STDOUT_FILENO, argv[0], strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);

	snprintf(er, sizeof(er), "%d", counter);
	write(STDOUT_FILENO, er, strlen(er));

	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, input, strlen(input));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	char promptStr[] = "$ ";

	write(STDOUT_FILENO, promptStr, sizeof(promptStr) - 1);
}

