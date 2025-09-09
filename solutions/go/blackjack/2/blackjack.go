// Package blackjack provides functions for parsing cards and determining the player's choice on the first turn.
package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	switch card {
	case "ace":
		return 11
	case "two":
		return 2
	case "three":
		return 3
	case "four":
		return 4
	case "five":
		return 5
	case "six":
		return 6
	case "seven":
		return 7
	case "eight":
		return 8
	case "nine":
		return 9
	case "ten", "jack", "queen", "king":
		return 10
	default:
		return 0
	}
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	if card1 == "ace" && card2 == "ace" {
		return "P"
	}

	var cardSum int = ParseCard(card1) + ParseCard(card2)
	var dealerNum int = ParseCard(dealerCard)

	switch {
	case cardSum == 21 && dealerNum < 10:
		return "W"
	case cardSum >= 17:
		return "S"
	case cardSum >= 12 && dealerNum < 7:
		return "S"
	default:
		return "H"
	}
}
