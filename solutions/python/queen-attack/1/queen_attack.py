class Queen:
    __row_min, __row_max = 0, 7
    __col_min, __col_max = 0, 7

    def __init__(self, row, column):
        if row < Queen.__row_min:
            raise ValueError("row not positive")
        if row > Queen.__row_max:
            raise ValueError("row not on board")
        if column < Queen.__col_min:
            raise ValueError("column not positive")
        if column > Queen.__col_max:
            raise ValueError("column not on board")

        self.row = row
        self.col = column

    def can_attack(self, another_queen):
        if (self.row, self.col) == (another_queen.row, another_queen.col):
            raise ValueError("Invalid queen position: both queens in the same square")

        return (
            self.col == another_queen.col
            or self.row == another_queen.row
            or abs(self.row - another_queen.row) == abs(self.col - another_queen.col)
        )
