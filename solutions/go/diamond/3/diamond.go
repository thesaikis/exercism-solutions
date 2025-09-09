package diamond

import (
	"errors"
	"math"
	"strings"
)

// Gen returns a string with a diamond pattern from 'A' to the given char.
func Gen(char byte) (string, error) {
	var sb strings.Builder

	if char < 'A' || char > 'Z' {
		return "", errors.New("unsupported char")
	}

	for i := 0; i <= int(char-'A')*2; i++ {
		for j := 0; j <= int(char-'A')*2; j++ {
			if int(math.Abs(float64(j-(int(char-'A'))))) == i || int(math.Abs(float64(j-(int(char-'A'))))) == int(char-'A')*2-i {
				sb.WriteByte(char - byte(math.Abs(float64(i-(int(char-'A'))))))
			} else {
				sb.WriteRune(' ')
			}
		}
		sb.WriteRune('\n')
	}

	return sb.String()[:sb.Len()-1], nil
}
