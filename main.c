#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv []) {
	// this storage is unneccesary but, it improves code clarity (i think)
	char instructions[1000];
	int length = strlen(argv[1]);
	strncpy(instructions, argv[1]++, length - 2);
	length -= 2;

	char array[65536] = {0};
	char *ptr = array;

	for (int instruction = 0; instruction < length; ++instruction) {
		char current_instruction = instructions[instruction];
		
		switch (current_instruction) {
			case '>':
				ptr++;
				break;
			case '<':
				ptr--;
				break;
			case '+':
				(*ptr)++;
				break;
			case '-':
				(*ptr)--;
				break;
			case '.':
				printf("%c", *ptr);
				break;
			case ',':
				scanf("%c", ptr);
				break;
			case '[':
				if (!(*ptr)) {
					int c = 1;
					while (c != 0) {
						instruction++;
						if (instructions[instruction] == '[') {
							c++;
						} else if (instructions[instruction] == ']') {
							c--;
						}
					}
				}
				break;
			case ']':
				if (*ptr) {
					int c = 1;
					while (c != 0) {
						instruction--;
						if (instructions[instruction] == ']') {
							c++;
						} else if (instructions[instruction] == '[')  {
							c--;
						}
					}
				}
				break;
			default:
				printf("Invalid instruction\n");
				exit(1);
				break;
		}

		if (ptr < array || ptr > array + 65536) {
			printf("Invalid pointer address");
			exit(1);
		}	
	}

	printf("\n");
	
	return 0;
}
