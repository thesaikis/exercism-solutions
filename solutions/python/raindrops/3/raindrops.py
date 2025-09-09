def convert(n):
    return "".join(f"Pl{c}ng" for c, mod in [("i", 3), ("a", 5), ("o", 7)] if not n % mod) or str(n)
