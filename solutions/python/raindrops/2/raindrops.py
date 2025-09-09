def convert(n):
    return "".join(word for word, mod in [("Pling", 3), ("Plang", 5), ("Plong", 7)] if n % mod == 0) or str(n)
