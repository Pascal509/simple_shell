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
		char *my_path = NULL;

		while (tok != NULL && counter < MAX_COMMAND_LENGTH / 2) 
		{
			args[counter++] = tok;
			tok = strtok(NULL, " ");
		}
		args[counter] = NULL;

		if (strcmp(args[0], "env") == 0)
		{
			print_environ();
			exit(EXIT_SUCCESS);
		}

		my_path = my_envp(my_path);

		if (execve(my_path, args, environ) == -1)
		{
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
