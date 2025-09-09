module QueenAttack

let create (position: int * int) =
    match position with
    | r, c when c >= 0 && c < 8 && r >= 0 && r < 8 -> true
    | _ -> false

let canAttack (queen1: int * int) (queen2: int * int) =
    let (r1, c1), (r2, c2) = queen1, queen2
    let dist1 = r1 - r2 |> abs
    let dist2 = c1 - c2 |> abs
    dist1 = dist2 || r1 = r2 || c1 = c2
