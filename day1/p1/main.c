#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

int main(void) {
	char buffer[BUFFER_SIZE];
	FILE* file = fopen("input", "r");
	int sum = 0;
	int max = 0;

	if (file == NULL) {
		printf("File does not exist\n");
		exit(1);
	}

	while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
		if (buffer[0] == '\n') {
			if (sum > max) {
				max = sum;
			}
			sum = 0;
		} else {
		sum += atoi(buffer);
		}
	}

	printf("maximum is %d\n", max);
	
	fclose(file);
}
