/*
 * Author: Hwieun Kim
 * Purpose: wc command
 * Copyright: 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int c(char *path) {
	FILE *file = fopen(*path, "r");
	if (file == NULL) return -1;


	int words = 0;
	char c;
	int is_word = 0;

	while((c = fgetc(file)) != EOF) {
	
		if(isspace(c)) {
			if(is_word) {
				words++;
				is_word=0;
			}
		}
		else is_word = 1;
	}

	if(is_word) words++;

	fclose(file);

	return words;
}

int main(int argc, char *argv[]) {
	int opt;
	char *file = argv[argc-1];

	// parse
	 while ((opt = getopt(argc, argv, "cwml:")) != -1) {
	 	switch(opt) {
	 	case 'c':
			printf("  %d %s\n", c(file), file);
	 		break;
		 default:
			fprintf(stderr, "Usage: %s [-c config_file]\n", argv[0]);
            return 1;
         }
     }

   // Check if the required option is provided
  //  if (config_file == NULL) {
  //      fprintf(stderr, "Option -c requires an argument.\n");
  //      return EXIT_FAILURE;
  //  }

    // Use the provided option and argument
    printf("Config file: %s\n", argv[2]);

    return 0;
}
