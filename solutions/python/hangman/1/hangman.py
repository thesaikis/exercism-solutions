# Game status categories
# Change the values as you see fit
STATUS_WIN = 'win'
STATUS_LOSE = 'lose'
STATUS_ONGOING = 'ongoing'


class Hangman:
    def __init__(self, word):
        self.remaining_guesses = 9
        self.status = STATUS_ONGOING
        self.word = word
        self.revealed = [False] * len(word)

    def guess(self, char):
        if self.status == STATUS_LOSE or self.status == STATUS_WIN:
            raise ValueError("The game has already ended.")

        did_reveal = False

        for i, c in enumerate(self.word):
            if not self.revealed[i] and char == c:
                self.revealed[i] = True
                did_reveal = True

        if not did_reveal:
            self.remaining_guesses -= 1

        if all(self.revealed):
            self.status = STATUS_WIN
        elif self.remaining_guesses == -1:
            self.status = STATUS_LOSE

    def get_masked_word(self):
        return ''.join(self.word[i] if c else '_' for i, c in enumerate(self.revealed))

    def get_status(self):
        return self.status
