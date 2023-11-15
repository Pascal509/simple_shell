#include "shell.h"

void exec_buffr(const char *buffr)
{
	pid_t new_pid = fork();
	char *my_path;
	char *env_path;
	char *dir;

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

		/* Check for command "env"*/
		if (strcmp(args[0], "env") == 0)
		{
			char **env = environ;
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			exit(EXIT_SUCCESS);
		}

		/* find my path in the executable
		 */
		my_path = NULL;
		env_path = getenv("PATH");

		if (env_path != NULL) 
		{
			dir = strtok(env_path, ":");
			while (dir != NULL)
			{
				/*Construct my path */
				my_path = (char *)malloc(strlen(dir) + strlen(args[0]) + 2);
				sprintf(my_path, "%s/%s", dir, args[0]);

				/* Search if the exe file exists*/
				if(access(my_path, X_OK) == 0)
				{
					break;
				}
				free(my_path);
				my_path = NULL;

				dir = strtok(NULL, ":");
			}
		}

		if (my_path == NULL)
		{
			fprintf(stderr, "Command does not exist: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}

		if (execve(my_path, args, environ) == -1) {
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
