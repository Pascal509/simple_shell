#include "shell.h"

int main (void)
{
	char *buffr;
	size_t buffr_size;
	size_t length;

	while (1) {
		display_my_prompt();
		buffr_size = 0;
		buffr = NULL;

		if (getline(&buffr, &buffr_size, stdin) == -1) {
			if (feof(stdin))
			{
				printf("\n");
			}
			else {
				perror("Error reading input");
			}
			break;
		}
		length = strlen(buffr);

		if (length > 0 && buffr[length - 1] == '\n') {
			buffr[length - 1] = '\0';
		}

		exec_buffr(buffr);
	}
	free(buffr);
	printf("Exiting shell...\n");

	return 0;
}
