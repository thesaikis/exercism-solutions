from random import randint

ABILITIES = [
    "strength",
    "dexterity",
    "constitution",
    "intelligence",
    "wisdom",
    "charisma",
]


def modifier(constitution):
    return (constitution - 10) // 2


class Character:
    def __init__(self):
        for ability in ABILITIES:
            setattr(self, ability, self.ability())
        self.hitpoints = modifier(self.constitution) + 10

    def ability(self):
        return sum(sorted((randint(1, 6) for _ in range(4)), reverse=True)[:3])
