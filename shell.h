#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100

extern char **environ;

int main (void);

void display_my_prompt();

void exec_buffr(const char *buffr);

#endif