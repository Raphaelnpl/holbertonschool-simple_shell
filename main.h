#ifndef MAIN_H
#define MAIN_H
#define MAX_ARGS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

int is_path(char *command);
char *_getenv(const char *name);
void print_env(char **environ);
void execute(char **args);
void handle_sigint(int sig);

#endif
