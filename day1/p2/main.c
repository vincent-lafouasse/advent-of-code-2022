#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64
#define PODIUM_SIZE 3

void print_arr(int *arr, int size);
void swap(int *a, int *b);
void sort(int *array, int size);
int sum_array(int *array, int size);

int main(void) {
  char buffer[BUFFER_SIZE];
  FILE *file = fopen("input", "r");
  int sum = 0;
  int podium[PODIUM_SIZE] = {0};

  if (file == NULL) {
    printf("File does not exist\n");
    exit(1);
  }

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    if (buffer[0] == '\n') {
      if (sum > podium[0]) {
        podium[0] = sum;
        sort(podium, PODIUM_SIZE);
      }
      sum = 0;
    } else {
      sum += atoi(buffer);
    }
  }

  printf("The top %d elves are carrying %d calories", PODIUM_SIZE,
         sum_array(podium, PODIUM_SIZE));

  fclose(file);
}

int sum_array(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += array[i];
  return sum;
}

void print_arr(int *arr, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *a, int *b) {
  int buffer = *a;
  *a = *b;
  *b = buffer;
}

void sort(int *array, int size) {
  for (int i = size - 1; i > 0 - 1; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[j + 1]) {
        swap(array + j, array + j + 1);
      }
    }
  }
}
