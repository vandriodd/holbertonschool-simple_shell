#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Def */
extern char **environ;

/* Macros */
#define DELIM " \n\t\a\r:="
#define INV " \t\n"

/* Prototypes */
int len_counter(char *str);
char **tokenize(char *str);
char *_getenv(const char *env);
int _execve(char *path, char **args);
char *_which(char *env_value, char **command);
void free_array(char **array);
int inval_prompt(char *input);

#endif
