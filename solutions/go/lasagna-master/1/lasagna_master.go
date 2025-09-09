// Package lasagna provides functions for managing lasagna recipes.
package lasagna

// PreparationTime returns the time to prepare a lasagna,
// given the layers and the time to cook each one.
func PreparationTime(layers []string, time int) int {
	if time <= 0 {
		time = 2
	}

	return len(layers) * time
}

// Quantities returns the grams of noodles and sauce needed for a lasagna,
// given the layers of the lasagna.
func Quantities(layers []string) (int, float64) {
	var gramsNoodles int = 0
	var gramsSauce float64 = 0

	for _, v := range layers {
		if v == "noodles" {
			gramsNoodles += 50
		} else if v == "sauce" {
			gramsSauce += 0.2
		}
	}

	return gramsNoodles, gramsSauce
}

// AddSecretIngredient modifies a recipe for a given lasagna,
// given another recipe with the secret ingredient at the end.
func AddSecretIngredient(friendsList []string, myList []string) {
	friendListLength := len(friendsList)
	myListLength := len(myList)

	myList[myListLength-1] = friendsList[friendListLength-1]
}

// ScaleRecipe returns the scaled up quantities,
// given the initial quantities and poritons.
func ScaleRecipe(quantities []float64, portions int) []float64 {
	var newQuantities []float64

	for _, v := range quantities {
		newQuantities = append(newQuantities, float64(portions)/2*v)
	}

	return newQuantities
}
