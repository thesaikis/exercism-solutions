def equilateral(sides):
    return all(side == sides[0] and side != 0 for side in sides)


def isosceles(sides):
    return is_valid(*sides) and len(set(sides)) in [1, 2]


def scalene(sides):
    return is_valid(*sides) and len(set(sides)) == 3


def is_valid(s1, s2, s3):
    return s1 + s2 >= s3 and s2 + s3 >= s1 and s1 + s3 >= s2
