class ConnectGame:
    def __init__(self, board):
        self.board = [line.split() for line in board.splitlines()]
        self.winner = ""

        self.search_winner(queue=[(0, r) for r in range(len(self.board))], target="X")

        if self.winner == "":
            self.search_winner(queue=[(c, 0) for c in range(len(self.board[0]))], target="O")

    def get_winner(self):
        return self.winner

    def search_winner(self, queue=[], target="X"):
        visited = set()

        while len(queue) > 0:
            x, y = queue.pop()

            if (x, y) in visited:
                continue

            visited.add((x, y))

            if self.board[y][x] == target:
                if ( target == "X" and x == len(self.board[y]) - 1 or target == "O" and y == len(self.board) - 1):
                    self.winner = target
                    break

                for dx, dy in [(0, 1), (0, -1), (1, 0), (1, -1), (-1, 0), (-1, 1)]:
                    if y + dy < 0 or y + dy >= len(self.board):
                        continue
                    if x + dx < 0 or x + dx >= len(self.board[y]):
                        continue

                    queue.append((x + dx, y + dy))
