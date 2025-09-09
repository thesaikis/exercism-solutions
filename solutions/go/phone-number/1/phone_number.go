package phonenumber

import (
	"errors"
	"strings"
)

// Number returns the valid phone number in the given string if found.
func Number(phoneNumber string) (string, error) {
	var sb strings.Builder

	for _, ch := range phoneNumber {
		if ch >= '0' && ch <= '9' {
			sb.WriteRune(ch)
		}
	}

	numberString := sb.String()

	if sb.Len() < 10 || sb.Len() > 11 {
		return "", errors.New("invalid number")
	} else if sb.Len() == 11 {
		if numberString[0] != '1' {
			return "", errors.New("invalid number")
		}
		numberString = sb.String()[1:]
	}

	if numberString[0] < '2' || numberString[3] < '2' {
		return "", errors.New("invalid number")
	}

	return numberString, nil
}

// AreaCode returns only the area code of a valid phone number.
func AreaCode(phoneNumber string) (string, error) {
	number, err := Number(phoneNumber)

	if err != nil {
		return "", err
	}
	return number[:3], nil
}

// Format returns a formatted string of a phone number.
func Format(phoneNumber string) (string, error) {
	number, err := Number(phoneNumber)

	if err != nil {
		return "", err
	}
	return "(" + number[:3] + ") " + number[3:6] + "-" + number[6:], nil
}
