#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, our_strlen(c)))

/**
 * struct bulltin - have a bultin to handle and func to exc
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
size_t our_strlen(const char *str);
char *our_strcat(const char *s1, const char *s2);
char *our_strncpy(char *dest, const char *src, size_t n);
char *our_strcpy(char *dest, const char *src);
char *our_strchr(const char *str, int character);
char *our_strdup(const char *src);
char *our_strtok(char *str, const char *dl);
unsigned int check_delim(char c, const char *str);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int our_strcmp(const char *s1, const char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *our_itoa(unsigned int n);
int our_strncmp(const char *s1, const char *s2, size_t n);
void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *our_memcpy(char *dest, char *src, unsigned int n);
void *our_calloc(unsigned int size);
void *our_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
void prompt(void);
void signal_to_handel(int sig);
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void our_prerror(char **argv, int c, char **cmd);
char *_getline(void);
int path_cmd(char **line);
char *_getenv(const char *name);
char **analze_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int our_builtin(char **cmd);
void our_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void exit_bul(char **cmd, char *input, char **argv, int c);
int dis_echo(char **cmd);
char *get_command(char *cmd);
int _setenv(const char *nm, const char *v, int o);
char **split_string(char *buf, char *dl);
char *read_input(void);
char **parse_input(char *input);
void execute_command(char **cmd);

#endif
