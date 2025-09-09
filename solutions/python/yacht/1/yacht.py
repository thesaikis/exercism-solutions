# Score categories.
# Change the values as you see fit.
from collections import Counter


YACHT = 0
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11


def score(dice, category):
    if category == YACHT:
        return 50 if all(d == dice[0] for d in dice) else 0
    if ONES <= category <= SIXES:
        return category * dice.count(category)
    if category == FULL_HOUSE:
        return sum(dice) if all(count == 2 or count == 3 for _, count in Counter(dice).items()) else 0
    if category == FOUR_OF_A_KIND:
        counts = Counter(dice)
        return sum(d * 4 for d, count in counts.items() if count >= 4) if all(count == 1 or count >= 4 for _, count in counts.items()) else 0
    if category == LITTLE_STRAIGHT:
        return 30 if sorted(dice) == [1,2,3,4,5] else 0
    if category == BIG_STRAIGHT:
        return 30 if sorted(dice) == [2,3,4,5,6] else 0

    return sum(dice)
