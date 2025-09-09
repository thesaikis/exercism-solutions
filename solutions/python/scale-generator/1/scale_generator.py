FLAT_SCALE = ["C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"]
SHARP_SCALE = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]
VALID_SHARPS = set(["C", "a", "G", "D", "A", "E", "B", "F#", "e", "b", "f#", "c#", "g#", "d#"])
VALID_FLATS = set(["F", "Bb", "Eb", "Ab", "Db", "Gb", "d", "g", "c", "f", "bb", "eb"])
JUMPS = {"A": 3, "M": 2, "m": 1}


class Scale:
    def __init__(self, tonic):
        if tonic in VALID_SHARPS:
            self.scale = SHARP_SCALE
        else:
            self.scale = FLAT_SCALE

        self.tonic = tonic[0].upper() + tonic[1:]
        self.start = self.scale.index(self.tonic)

    def chromatic(self):
        return [
            self.scale[i % len(self.scale)]
            for i in range(self.start, self.start + len(self.scale))
        ]

    def interval(self, intervals):
        index = self.start
        scale = [self.scale[index]]

        for c in intervals:
            index += JUMPS[c]
            scale.append(self.scale[index % len(self.scale)])

        return scale
