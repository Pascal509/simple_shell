#include "shell.h"

int main()
{
	char *buffr;
	size_t buffr_size;
	size_t length;
	length = 0;

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
		length = strlen(buffr);

		if (length > 0 && buffr[length - 1] == '\n')
		{
			buffr[length - 1] = '\0';
		}
		/*if (strcmp(buffr, "exit") == 0)
                {
                        printf("Exiting shell...\n");
                        free(buffr);
                        exit(EXIT_SUCCESS);
                }*/
		exec_buffr(buffr);

	}
	free(buffr);

	return (0);
}
