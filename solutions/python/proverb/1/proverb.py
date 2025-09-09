def proverb(*items, **kwargs):
    if len(items) == 0:
        return []

    return [
        f"For want of a {items[i-1]} the {items[i]} was lost."
        for i in range(1, len(items))
    ] + [
        f"And all for the want of a{' ' + kwargs['qualifier'] if kwargs['qualifier'] is not None else ''} {items[0]}."
    ]
