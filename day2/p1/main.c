#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

typedef enum {
  ROCK,
  PAPER,
  SCISSORS,
} Play;

typedef struct {
  Play player_choice;
  Play opponent_choice;
} Round;

char *play_repr(Play play);
void parse_round(char *to_parse);
void print_round(Round round);
Play parse_opponent_play(char opponent_encoded);
Play parse_player_play(char player_encoded);

int main(void) {
  char buffer[BUFFER_SIZE];
  FILE *file = fopen("input", "r");

  if (file == NULL) {
    printf("File does not exist\n");
    exit(1);
  }

  printf("first round:\n");
  fgets(buffer, BUFFER_SIZE, file);
  printf("%s", buffer);
  parse_round(buffer);

  // while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
  // 	printf("%s", buffer);
  // }

  fclose(file);
}

void parse_round(char *to_parse) {
  char opponent_encoded;
  char player_encoded;

  sscanf(to_parse, "%c %c", &opponent_encoded, &player_encoded);
  printf("opp:\n\t%c\n", opponent_encoded);
  printf("opp played %s\n", play_repr(parse_opponent_play(opponent_encoded)));
  printf("player:\n\t%c\n", player_encoded);
  printf("player played %s\n", play_repr(parse_opponent_play(player_encoded)));
}

Play parse_opponent_play(char opponent_encoded) {
  switch (opponent_encoded) {
  case 'A':
    return ROCK;
  case 'B':
    return PAPER;
  case 'C':
    return SCISSORS;
  default:
    return -1;
  }
}

Play parse_player_play(char player_encoded) {
  switch (player_encoded) {
  case 'X':
    return ROCK;
  case 'Y':
    return PAPER;
  case 'Z':
    return SCISSORS;
  default:
    return -1;
  }
}

char *play_repr(Play play) {
  switch (play) {
  case ROCK:
    return "Rock";
  case PAPER:
    return "Paper";
  case SCISSORS:
    return "Scissors";
  default:
    return "Invalid";
  }
}
