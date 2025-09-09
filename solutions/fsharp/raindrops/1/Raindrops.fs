module Raindrops

let rec divideOutFactors n factor =
    if n % factor = 0 then
        divideOutFactors (n / factor) factor
    else
        n

let rec convertRec (number: int) : string =
    match number with
    | n when n % 3 = 0 -> "Pling" + convertRec (divideOutFactors n 3)
    | n when n % 5 = 0 -> "Plang" + convertRec (divideOutFactors n 5)
    | n when n % 7 = 0 -> "Plong" + convertRec (divideOutFactors n 7)
    | _ -> ""

let convert (number: int) : string =
    let result = convertRec number
    if result = "" then number.ToString() else result
