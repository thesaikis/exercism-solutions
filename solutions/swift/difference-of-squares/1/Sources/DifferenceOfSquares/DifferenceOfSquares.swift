class Squares {
    var squareOfSum: Int
    var sumOfSquares: Int
    var differenceOfSquares: Int
      
    init(_ n: Int) {
        squareOfSum = ((n * (n + 1)) / 2) * ((n * (n + 1)) / 2)
        sumOfSquares = n * (n + 1) * (2 * n + 1) / 6
        differenceOfSquares = squareOfSum - sumOfSquares
    }
}
