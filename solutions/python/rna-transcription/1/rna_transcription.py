def to_rna(dna_strand):
    return dna_strand.translate(str.maketrans({"G": "C", "C": "G", "T": "A", "A": "U"}))
