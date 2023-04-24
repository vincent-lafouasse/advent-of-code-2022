from enum import Enum

ROCK, PAPER, SCISSORS = range(1, 4)

encoding1 = {
    "A": ROCK,
    "B": PAPER,
    "C": SCISSORS,
    "X": ROCK,
    "Y": PAPER,
    "Z": SCISSORS,
}


def main():
    with open("input", "r") as strategy_raw:
        encoded_strategy = parse_raw_input(strategy_raw)
        strategy = decode_strategy1(strategy_raw)
        scores = [round_outcome(opponent_action, player_action) + player_action for [opponent_action, player_action] in strategy]
        score = sum(scores)
        print(score)


def parse_raw_input(raw_input):
    encoded_strategy = raw_input.read().split("\n")
    return [round.split(" ") for round in encoded_strategy if round != ""]


def decode_strategy1(encoded_strategy):
     return [
        [encoding1[opponent_action], encoding1[player_action]]
        for [opponent_action, player_action] in encoded_strategy
    ]


def round_outcome(opponent_action, player_action):
    win_score, draw_score, loss_score = 6, 3, 0

    outcome = (player_action - opponent_action) % 3
    if outcome == 0:
        return draw_score
    if outcome == 1:
        return win_score
    if outcome == 2:
        return loss_score


if __name__ == "__main__":
    main()
