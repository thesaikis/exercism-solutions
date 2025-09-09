module DifferenceOfSquares

let squareOfSum (n: int): int = ((n * (n + 1)) / 2) * ((n * (n + 1)) / 2)

let sumOfSquares (n: int): int = n * (n + 1) * (2 * n + 1) / 6

let differenceOfSquares (n: int): int = squareOfSum n - sumOfSquares n