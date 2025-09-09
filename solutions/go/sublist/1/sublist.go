package sublist

// isSublist returns if subList is contained in mainList.
func isSublist(mainList, subList []int) bool {
	for i := 0; i <= len(mainList)-len(subList); i++ {
		match := true
		for j := 0; j < len(subList); j++ {
			if mainList[i+j] != subList[j] {
				match = false
				break
			}
		}
		if match {
			return true
		}
	}

	return false
}

// Sublist returns the relationship between the two given lists.
func Sublist(l1, l2 []int) Relation {
	l1IsContained := isSublist(l2, l1)
	l2IsContained := isSublist(l1, l2)

	if l1IsContained && l2IsContained {
		return RelationEqual
	} else if l1IsContained {
		return RelationSublist
	} else if l2IsContained {
		return RelationSuperlist
	}

	return RelationUnequal
}
