package yacht

import (
	"reflect"
	"sort"
)

// scoreYacht returns 50 if all the dice are equal, 0 if not.
func scoreYacht(dice []int) int {
	firstDie := dice[0]

	for i := 1; i < len(dice); i++ {
		if dice[i] != firstDie {
			return 0
		}
	}

	return 50
}

// scoreSingleType returns the sum of the occurrences of single in dice.
func scoreSingleType(dice []int, single int) int {
	count := 0

	for _, die := range dice {
		if die == single {
			count++
		}
	}

	return single * count
}

// scoreFullHouse returns the sum of the dice if its a full house.
func scoreFullHouse(dice []int) int {
	firstCount, firstNum := -1, -1
	secondCount, secondNum := -1, -1

	for _, die := range dice {
		if firstNum == -1 {
			firstCount = 1
			firstNum = die
		} else if secondNum == -1 && die != firstNum {
			secondCount = 1
			secondNum = die
		} else if die == firstNum {
			firstCount++
		} else if die == secondNum {
			secondCount++
		}
	}

	if (firstCount == 3 && secondCount == 2) || (firstCount == 2 && secondCount == 3) {
		return firstCount*firstNum + secondCount*secondNum
	}

	return 0
}

// scoreFourOfAKind returns the sum of the 4 dice, if they exist.
func scoreFourOfAKind(dice []int) int {
	counts := make(map[int]int)

	for _, die := range dice {
		counts[die]++
	}

	for die, count := range counts {
		if count >= 4 {
			return die * 4
		}
	}

	return 0
}

// scoreStraight returns 30 if the dice is equal to the given straight.
func scoreStraight(dice []int, straight []int) int {
	sort.Ints(dice)
	if reflect.DeepEqual(dice, straight) {
		return 30
	}
	return 0
}

// scoreChoice returns the sum of the dice.
func scoreChoice(dice []int) (sum int) {
	for _, die := range dice {
		sum += die
	}
	return
}

// Score returns the score of the dice for the given category.
func Score(dice []int, category string) int {
	switch category {
	case "yacht":
		return scoreYacht(dice)
	case "ones":
		return scoreSingleType(dice, 1)
	case "twos":
		return scoreSingleType(dice, 2)
	case "threes":
		return scoreSingleType(dice, 3)
	case "fours":
		return scoreSingleType(dice, 4)
	case "fives":
		return scoreSingleType(dice, 5)
	case "sixes":
		return scoreSingleType(dice, 6)
	case "full house":
		return scoreFullHouse(dice)
	case "four of a kind":
		return scoreFourOfAKind(dice)
	case "little straight":
		return scoreStraight(dice, []int{1, 2, 3, 4, 5})
	case "big straight":
		return scoreStraight(dice, []int{2, 3, 4, 5, 6})
	default:
		return scoreChoice(dice)
	}
}
