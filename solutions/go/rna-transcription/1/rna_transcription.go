// Package strand provides a function for transcribing RNA.
package strand

var toRnaMap = map[rune]string{
	'G': "C", 'C': "G", 'T': "A", 'A': "U",
}

// ToRNA returns the RNA complement string of the given DNA sequence string.
func ToRNA(dna string) (rna string) {
	for _, c := range dna {
		rna += toRnaMap[c]
	}
	return
}
