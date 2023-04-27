#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64

char find_duplicate_item(char* sack);
int char_priority(char c);

int main(void) {
  char buffer[BUFFER_SIZE];
  FILE* file = fopen("./src/input.txt", "r");
  int total = 0;

  if (file == NULL) {
    printf("File does not exist\n");
    exit(1);
  }

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    char duplicate = find_duplicate_item(buffer);
    total += char_priority(duplicate);
  }
  printf("total: %d\n", total);
}

char find_duplicate_item(char* sack) {
  int sack_size = (strlen(sack) - 1) / 2;
  char* sack1 = sack;
  char* sack2 = sack + sack_size;
  for (int i = 0; i < sack_size; i++) {
    for (int j = 0; j < sack_size; j++) {
      if (sack1[i] == sack2[j]) {
        return sack1[i];
      }
    }
  }
  return '\0';
}

int char_priority(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 1;
  } else if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 27;

  } else {
    return -1;
  }
}
