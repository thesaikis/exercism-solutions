def largest_product(series, size):
    if size > len(series):
        raise ValueError("span must be smaller than string length")
    if any(not c.isdigit() for c in series):
        raise ValueError("digits input must only contain digits")
    if size < 0:
        raise ValueError("span must not be negative")
    
    max_product = 0

    for i in range(len(series) - size + 1):
        curr = 1
        for n in range(i, i + size):
            curr *= int(series[n])
        max_product = max(curr, max_product)
    
    return max_product
