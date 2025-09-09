from string import ascii_uppercase
from random import shuffle


class Robot:
    names = []

    for c1 in ascii_uppercase:
        for c2 in ascii_uppercase:
            for num in range(1000):
                names.append(f"{c1}{c2}{num}")
    shuffle(names)

    def __init__(self):
        self.name = Robot.names.pop()

    def name(self):
        return self.name

    def reset(self):
        self.name = Robot.names.pop()
