#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64
#define LOSS_PTS 0
#define DRAW_PTS 3
#define WIN_PTS 6

typedef enum {
  ROCK = 1,
  PAPER = 2,
  SCISSORS = 3,
} Play;

typedef struct {
  Play player_choice;
  Play opponent_choice;
} Round;

char* play_repr(Play play);
Round parse_round(char* to_parse);
void print_round(Round round);
Play parse_opponent_play(char opponent_encoded);
Play parse_player_play(char player_encoded);
int settle_round(Round round);

Round parse_true_round(char* to_parse);
Play parse_true_player_play(char player_encoded, Play opponent_action);

int settle_round(Round round) {
  int outcome = (round.player_choice - round.opponent_choice + 3) % 3;
  switch (outcome) {
    case 0:
      return DRAW_PTS + round.player_choice;
    case 1:
      return WIN_PTS + round.player_choice;
    case 2:
      return LOSS_PTS + round.player_choice;
    default:
      return -1;
  }
}

int main(void) {
  char buffer[BUFFER_SIZE];
  FILE* file = fopen("./subject/input.txt", "r");
  int total_score = 0;

  if (file == NULL) {
    printf("File does not exist\n");
    exit(1);
  }

  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    Round round = parse_true_round(buffer);
    total_score += settle_round(round);
  }

  printf("total score: %d\n", total_score);

  fclose(file);
}

Round parse_true_round(char* to_parse) {
  char opponent_encoded;
  char player_encoded;
  Play opponent_action;
  Play player_action;

  sscanf(to_parse, "%c %c", &opponent_encoded, &player_encoded);
  opponent_action = parse_opponent_play(opponent_encoded);
  player_action = parse_true_player_play(player_encoded, opponent_action);
  Round round = {player_action, opponent_action};
  return round;
}

Round parse_round(char* to_parse) {
  char opponent_encoded;
  char player_encoded;

  sscanf(to_parse, "%c %c", &opponent_encoded, &player_encoded);
  Round round = {parse_player_play(player_encoded),
                 parse_opponent_play(opponent_encoded)};
  return round;
}

Play parse_true_player_play(char player_encoded, Play opponent_action) {
  int player_choice;
  switch (player_encoded) {
    case 'X': {
      player_choice = (int)opponent_action - 1;
      break;
    }
    case 'Y': {
      player_choice = (int)opponent_action;
      break;
    }
    case 'Z': {
      player_choice = (int)opponent_action + 1;
      break;
    }
    default:
      exit(1);
  }
  player_choice %= 3;
  return player_choice == 0 ? 3 : player_choice;
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

char* play_repr(Play play) {
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
