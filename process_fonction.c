#include "shell.h"
/**
 * pid_t our_fork - PID
 *
 * Return: return fork()
 */

pid_t our_fork(void)
{
	return (fork());
}

/*
 *
 * our_wait - return rien
 * @status: Pointer to int
 */

void our_wait(int *status)
{
	wait(status);
}

/*
 * our_execve - execve function
 * @path : pointer to str
 * @ argv : srgument
 * @env:envirmment
 * Returne : return execve().
 */


int our_execve(const char *path, char *const argv[], char *const env[])
{
	return (execve(path, argv, env));
}
