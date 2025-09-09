module CarsAssemble

let successRate (speed: int) : float =
    match speed with
    | 10 -> 0.77
    | s when s >= 9 -> 0.80
    | s when s >= 5 -> 0.90
    | s when s >= 1 -> 1.00
    | _ -> 0.0


let productionRatePerHour (speed: int) : float = float (221 * speed) * successRate speed

let workingItemsPerMinute (speed: int) : int = int (productionRatePerHour speed) / 60
