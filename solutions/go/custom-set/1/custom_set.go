package stringset

import "strings"

type Set map[string]bool

func New() Set {
	return make(Set)
}

func NewFromSlice(l []string) Set {
	set := make(Set)

	for _, elem := range l {
		set[elem] = true
	}

	return set
}

func (s Set) String() string {
	var sb strings.Builder
	sb.WriteRune('{')

	elemsPrinted := 0
	for elem := range s {
		sb.WriteRune('"')
		sb.WriteString(elem)
		sb.WriteRune('"')
		if elemsPrinted < len(s)-1 {
			sb.WriteString(", ")
		}
		elemsPrinted++
	}

	sb.WriteRune('}')
	return sb.String()
}

func (s Set) IsEmpty() bool {
	return len(s) == 0
}

func (s Set) Has(elem string) bool {
	return s[elem]
}

func (s Set) Add(elem string) {
	s[elem] = true
}

func Subset(s1, s2 Set) bool {
	for elem := range s1 {
		if !s2[elem] {
			return false
		}
	}

	return true
}

func Disjoint(s1, s2 Set) bool {
	for elem := range s1 {
		if s2[elem] {
			return false
		}
	}

	return true
}

func Equal(s1, s2 Set) bool {
	return Subset(s1, s2) && Subset(s2, s1)
}

func Intersection(s1, s2 Set) Set {
	newSet := make(Set)

	for elem := range s1 {
		if s2[elem] {
			newSet[elem] = true
		}
	}

	return newSet
}

func Difference(s1, s2 Set) Set {
	newSet := make(Set)

	for elem := range s1 {
		if !s2[elem] {
			newSet[elem] = true
		}
	}

	return newSet
}

func Union(s1, s2 Set) Set {
	newSet := make(Set)

	for elem := range s1 {
		newSet[elem] = true
	}

	for elem := range s2 {
		newSet[elem] = true
	}

	return newSet
}
