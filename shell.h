#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_IN_LEN 1024


void prompt(char **av, char **env);
char *get_command(char *cmd);
int mun(int N1, int N2);
char *_getenv(const char *name);
int _setenv(const char *nm, const char *v, int o);
char **split_string(char *buf, char *dl);
pid_t our_fork(void);
void our_wait(int *status);
int our_execve(const char *path, char *const argv[], char *const envp[]);
char *our_strcat(const char *s1, const char *s2);
char *our_strncpy(char *dest, const char *src, size_t n);
char *our_strcpy(char *dest, const char *src);
char *our_strtok(char *str, const char *delim);
size_t our_strlen(const char *str);
int our_strcmp(const char *s1, const char *s2);
void our_exit(void);

extern char **envi;
extern char **environ;

#endif
