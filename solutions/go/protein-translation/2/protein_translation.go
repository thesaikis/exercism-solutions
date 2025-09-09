package protein

import "errors"

var (
	ErrStop        = errors.New("stop codon")
	ErrInvalidBase = errors.New("invalid base")
)

var codonToProtein = map[string]string{
	"AUG": "Methionine",
	"UUU": "Phenylalanine",
	"UUC": "Phenylalanine",
	"UUA": "Leucine",
	"UUG": "Leucine",
	"UCU": "Serine",
	"UCC": "Serine",
	"UCA": "Serine",
	"UCG": "Serine",
	"UAU": "Tyrosine",
	"UAC": "Tyrosine",
	"UGU": "Cysteine",
	"UGC": "Cysteine",
	"UGG": "Tryptophan",
}

// FromRNA returns the polypeptide sequence of the given RNA string.
func FromRNA(rna string) ([]string, error) {
	res := []string{}

	for i := 0; i < len(rna)-2; i += 3 {
		codon := rna[i : i+3]

		protein, ok := codonToProtein[codon]

		if codon == "UAA" || codon == "UAG" || codon == "UGA" {
			return res, nil
		} else if !ok {
			return nil, ErrInvalidBase
		} else {
			res = append(res, protein)
		}
	}

	return res, nil
}

// FromCodon returns the polypeptide for the given codon.
func FromCodon(codon string) (string, error) {
	protein, ok := codonToProtein[codon]

	if codon == "UAA" || codon == "UAG" || codon == "UGA" {
		return "", ErrStop
	} else if !ok {
		return "", ErrInvalidBase
	} else {
		return protein, nil
	}
}
