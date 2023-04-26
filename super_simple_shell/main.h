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
#define DELIM " \n\t:="

/* Prototypes */
int len_counter(char *str);
char **tokenize(char *str);
char *_getenv(const char *env);
int _execve(char **args);
char **_which(char *env_value);

#endif