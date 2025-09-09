module Hamming

let checkEq a b = if a <> b then 1 else 0

let rec distanceHelper strand1 strand2 =
    match (strand1, strand2) with
    | (h1 :: t1, h2 :: t2) -> (h1, h2) ||> checkEq |> (+) (distanceHelper t1 t2)
    | _, _ -> 0

let distance (strand1: string) (strand2: string) : int option =
    if strand1.Length <> strand2.Length then
        None
    else
        distanceHelper (strand1 |> Seq.toList) (strand2 |> Seq.toList) |> Some
