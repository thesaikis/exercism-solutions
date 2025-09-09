package allergies

var strAllergies = []string{"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"}

func Allergies(allergies uint) []string {
	allergicList := make([]string, 0)

	for i := 0; i < len(strAllergies); i++ {
		if allergies&(1<<i) != 0 {
			allergicList = append(allergicList, strAllergies[i])
		}
	}

	return allergicList
}

func AllergicTo(allergies uint, allergen string) bool {
	for i := 0; i < len(strAllergies); i++ {
		if strAllergies[i] == allergen && allergies&(1<<i) != 0 {
			return true
		}
	}

	return false
}
