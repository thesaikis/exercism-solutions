package robotname

import (
	"errors"
	"math/rand"
)

type Robot struct {
	name string
}

const maxPossible = 26 * 26 * 10 * 10 * 10
const letSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
const numSet = "0123456789"

var namesGenerated = map[string]bool{}

func (r *Robot) Name() (string, error) {
	if len(namesGenerated) == maxPossible {
		return "", errors.New("all named have already been generated")
	}

	if r.name != "" {
		return r.name, nil
	}

	r.name = genName()
	for namesGenerated[r.name] {
		r.name = genName()
	}

	namesGenerated[r.name] = true

	return r.name, nil
}

func (r *Robot) Reset() {
	r.name = ""
}

func genName() string {
	name := make([]byte, 5)
	for idx := range name {
		if idx < 2 {
			name[idx] = letSet[rand.Intn(len(letSet))]
		} else {
			name[idx] = numSet[rand.Intn(len(numSet))]
		}
	}
	return string(name)
}
