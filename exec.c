#include "shell.h"

void exec_buffr(const char *buffr)
{
	pid_t new_pid = fork();

	if (new_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (new_pid == 0)
	{
		char *args[MAX_COMMAND_LENGTH / 2];
		int counter = 0;

		char *tok = strtok((char *)buffr, " ");
		while (tok != NULL && counter < MAX_COMMAND_LENGTH / 2) {
			args[counter++] = tok;
			tok = strtok(NULL, " ");
		}
		args[counter] = NULL;

		if (execve(args[0], args, NULL) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int current;
		waitpid(new_pid, &current, 0);
	}
}
