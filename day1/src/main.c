#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64
#define PODIUM_SIZE 3

void get_podium(FILE* file, int* podium, int podium_size);
void sort(int *array, int size);
int sum_array(int *array, int size);
void swap(int *a, int *b);
void print_arr(int *arr, int size);

int main(void) {
  FILE *file = fopen("./src/input.txt", "r");
  int podium[PODIUM_SIZE] = {0};
	int amount;

  if (file == NULL) {
    printf("File does not exist\n");
    exit(1);
  }
	
	get_podium(file, podium, PODIUM_SIZE);

	amount = sum_array(podium, PODIUM_SIZE);

	printf("The top %d elves are carrying %d calories\n", PODIUM_SIZE, amount);

  fclose(file);
}

void get_podium(FILE* file, int* podium, int podium_size) {
  char line[BUFFER_SIZE];
  int sum = 0;

  while (fgets(line, BUFFER_SIZE, file) != NULL) {
    if (line[0] == '\n') {
      if (sum > podium[0]) {
        podium[0] = sum;
        sort(podium, podium_size);
      }
      sum = 0;
    } else {
      sum += atoi(line);
    }
  }
}

void sort(int *array, int size) {
	// a bubble sort
  for (int i = size - 1; i > 0 - 1; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[j + 1]) {
        swap(array + j, array + j + 1);
      }
    }
  }
}

int sum_array(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += array[i];
  return sum;
}

void swap(int *a, int *b) {
  int buffer = *a;
  *a = *b;
  *b = buffer;
}

void print_arr(int *arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
