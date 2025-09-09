module Darts

let score (x: double) (y: double) : int =
    match System.Double.Hypot(x, y) with
    | d when d <= 1 -> 10
    | d when d <= 5 -> 5
    | d when d <= 10 -> 1
    | _ -> 0
