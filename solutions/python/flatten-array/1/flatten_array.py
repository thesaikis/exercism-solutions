def flatten(iterable):
    return [item for sublist in iterable for item in (flatten(sublist) if isinstance(sublist, list) else [sublist]) if item is not None]
