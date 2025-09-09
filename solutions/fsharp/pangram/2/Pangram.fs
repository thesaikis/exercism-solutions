module Pangram

let isPangram (input: string) : bool =
    input.ToLower() |> Set.ofSeq |> Set.isSubset (set [ 'a' .. 'z' ])
