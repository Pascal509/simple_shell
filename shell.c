#include "shell.h"

/**
 * main - entry point of program
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *buffr = "/bin/ls";
	size_t buffr_size;
	size_t length;
	int result;

	length = 0;

	if (argc > 1)
	{
		FILE *script = fopen(argv[1], "r");
		if (!script)
		{
			perror("Error opening file");
			return 1;
		}

		while (getline(&buffr, &buffr_size, script) != -1)
		{
			length = strlen(buffr);
			if (length > 0 && buffr[length - 1] == '\n')
			{
				buffr[length - 1] = '\0';
			}
			exec_buffr(buffr);
		}
		fclose(script);
	}
	else
	{
		while (1)
		{
			display_my_prompt();
			buffr_size = 0;
			buffr = NULL;

			if (getline(&buffr, &buffr_size, stdin) == -1)
			{
				if (feof(stdin))
					printf("\n");
				else
				{
					perror("Error reading input");
				}
				free(buffr);
				break;
			}
			buffr = strdup(buffr);
			length = strlen(buffr);
			system(buffr);


			if (length > 0 && buffr[length - 1] == '\n')
			{
				buffr[length - 1] = '\0';
			}

			exec_buffr(buffr);

			result = system(buffr);
			if (result == -1)
			{
				perror("error executing command");
			}
		}
	}
	return 0;
}
