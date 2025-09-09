PROTEIN_MAP = {
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


def proteins(strand):
    proteins = []

    for i in range(0, len(strand), 3):
        if strand[i : i + 3] in ("UAA", "UAG", "UGA"):
            return proteins
        elif protein := PROTEIN_MAP.get(strand[i : i + 3]):
            proteins.append(protein)

    return proteins
