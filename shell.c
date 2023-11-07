#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () 
{
	char *buffr;
	size_t display_chars;

	do {
		printf("#cisfun$");
		buffr = (char *)malloc(display_chars * sizeof(char));

		if (getline(&buffr, &display_chars, stdin) != NULL){
			//Remove trailing newline
			int len = strlen(buffr);
			if (len > 0 && buffr [len - 1] == '\n') {
				buffr[len - 1] = '\0';
			}

			if (strcmp(buffr, "Exit loop") == 0) {
				break; // Exit loop
			}
			printf("You entered: %s\n", buffr);
		}
		else if (feof(stdin)) {
			//Handle end-of-file
			printf("\n Exiting the program\n");
			break;
		}else {
			printf("Error in reading input.\n");
			break;
		} 
	}while (1); //infinite loop until user exits file

	return 0;

}
