from functools import cmp_to_key
from collections import Counter

RANKS = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]


def transform_hand(h):
    return sorted(RANKS.index(c[:-1]) for c in h.split())


# Returns a dictionary with the keys as the item counts.
def get_hand_counts(h):
    count = Counter(h)

    inverted = {}
    for key, value in count.items():
        inverted.setdefault(value, []).append(key)

    return inverted


# Returns if the given hand is a straight or not.
def is_straight(h):
    if h[-1] == RANKS.index("A") and h[0] == RANKS.index("2"):
        h = [-1] + h[:-1]

    for i in range(0, len(h) - 1):
        if h[i] != h[i + 1] - 1:
            return h, False

    return h, True


# Returns if the given hand is a flush or not.
def is_flush(h):
    split = h.split()
    return all(split[0][-1] == split[i][-1] for i in range(1, len(split)))


def pick_best_hand(hand_one, hand_two):
    one_flush = is_flush(hand_one)
    two_flush = is_flush(hand_two)

    hand_one = transform_hand(hand_one)
    hand_two = transform_hand(hand_two)

    hand_one, one_straight = is_straight(hand_one)
    hand_two, two_straight = is_straight(hand_two)

    # Simple logic to check for Staight flush
    # If both hands are straight flush, code will eventually
    # fall through to high card.
    if (one_flush and one_straight) or (two_flush and two_straight):
        if one_flush != two_flush:
            return one_flush - two_flush
        if one_straight != two_straight:
            return one_straight - two_straight

    one_counts = get_hand_counts(hand_one)
    two_counts = get_hand_counts(hand_two)

    one_quads = one_counts.get(4, [-1])
    two_quads = two_counts.get(4, [-1])

    # Give win to highest four of a kind.
    for one, two in zip(reversed(one_quads), reversed(two_quads)):
        if one != two:
            return one - two

    # Obtain the list of cards that appear twice, default to -1
    one_pairs = one_counts.get(2, [-1])
    two_pairs = two_counts.get(2, [-1])

    # Obtain the list of cards that appear three times, default to -1
    one_trips = one_counts.get(3, [-1])
    two_trips = two_counts.get(3, [-1])

    one_full, one_house = (
        one_pairs + one_trips,
        -1 not in one_pairs and -1 not in one_trips,
    )
    two_full, two_house = (
        two_pairs + two_trips,
        -1 not in two_pairs and -1 not in two_trips,
    )

    # Check if either hand is a full house.
    # Give with to highest triplet, otherwise pair.
    if one_house or two_house:
        for one, two in zip(reversed(one_full), reversed(two_full)):
            if one != two:
                return one - two

    # Give win to hand that is a flush, if only 1 hand is a flush.
    if one_flush != two_flush:
        return one_flush - two_flush

    # Give win to hand that is a straight, if only 1 is a straight.
    if one_straight != two_straight:
        return one_straight - two_straight

    # Give win to highest triplet.
    for one, two in zip(reversed(one_trips), reversed(two_trips)):
        if one != two:
            return one - two

    # Handle when we have a two pair versus a one pair.
    if len(one_pairs) != len(two_pairs):
        return len(one_pairs) - len(two_pairs)

    # Give the win to the highest pair.
    for one, two in zip(reversed(one_pairs), reversed(two_pairs)):
        if one != two:
            return one - two

    # Give the win to the high card.
    for one, two in zip(one_counts.get(1, [-1]), two_counts.get(1, [-1])):
        if one != two:
            return one - two

    return 0


def best_hands(hands):
    best_hand = max(hands, key=cmp_to_key(pick_best_hand))
    return [h for h in hands if pick_best_hand(best_hand, h) == 0]
