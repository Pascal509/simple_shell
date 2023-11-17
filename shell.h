#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100

int main();

extern char **environ;

void print_environ(void);

void my_envp(char *my_path);

void display_my_prompt();

void exec_buffr(char *buffr);

#endif
