#include "shell.h"

void my_envp(char *my_path)
{
	char *args[MAX_COMMAND_LENGTH / 2];
	int counter = 0;
	char *env_path;
	char *dir;

	/* find my path in the executable. */
	my_path = NULL;
	env_path = getenv("PATH");

	if (env_path != NULL)
	{
		dir = strtok(env_path, ":");
		while (dir != NULL)
		{
			/*Construct my path */
			args[counter] = NULL;
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
}
