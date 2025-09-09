module Accumulate

let accumulate (func: 'a -> 'b) (input: 'a list) : 'b list =
    let rec tailAccu acc =
        function
        | [] -> acc
        | h :: t -> tailAccu (func h :: acc) t

    tailAccu [] input |> List.rev
