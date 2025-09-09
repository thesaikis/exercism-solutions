module Grains

let square (n: int) : Result<uint64, string> =
    match n with
    | n when n > 0 && n < 65 -> (n - 1) |> pown 2UL |> Ok
    | _ -> Error "square must be between 1 and 64"

let total: Result<uint64, string> =
    [ 1..64 ] |> Seq.sumBy (fun n -> square n |> Result.defaultValue 0UL) |> Ok
