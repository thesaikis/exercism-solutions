EAST = 0
NORTH = 1
WEST = 2
SOUTH = 3
_DIR_END = 4


class Robot:
    _advance = {
        EAST: (lambda x, y: (x + 1, y)),
        NORTH: (lambda x, y: (x, y + 1)),
        WEST: (lambda x, y: (x - 1, y)),
        SOUTH: (lambda x, y: (x, y - 1)),
    }

    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self.direction = direction
        self.coordinates = (x_pos, y_pos)

    def move(self, moves):
        for m in moves:
            if m == "R":
                self.direction = (self.direction - 1 + _DIR_END) % _DIR_END
            elif m == "L":
                self.direction = (self.direction + 1) % _DIR_END
            else:  # assume m == "A"
                self.coordinates = Robot._advance[self.direction](*self.coordinates)
