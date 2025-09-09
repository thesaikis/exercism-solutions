def find_anagrams(word, candidates):
    return [
        cand
        for cand in candidates
        if sorted(cand.lower()) == sorted(word.lower()) and word.lower() != cand.lower()
    ]
