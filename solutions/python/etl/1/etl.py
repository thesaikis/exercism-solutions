def transform(legacy_data):
    return {c.lower(): p for p, chars in legacy_data.items() for c in chars}
