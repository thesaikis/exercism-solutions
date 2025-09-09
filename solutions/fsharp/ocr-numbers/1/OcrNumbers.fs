module OcrNumbers

// The flattened representation of each OCR number.
let refNums =
    [| " _ | ||_|   "
       "     |  |   "
       " _  _||_    "
       " _  _| _|   "
       "   |_|  |   "
       " _ |_  _|   "
       " _ |_ |_|   "
       " _   |  |   "
       " _ |_||_|   "
       " _ |_| _|   " |]

let convertSingleNum input =
    input
    |> Seq.map (fun elem -> elem |> Seq.chunkBySize 3 |> Seq.map (fun e -> new string (e)))
    |> Seq.transpose
    |> Seq.map (fun elem -> elem |> String.concat "")
    |> Seq.map (fun elem ->
        match Seq.tryFindIndex ((=) elem) refNums with
        | Some idx -> string idx
        | None -> "?")
    |> String.concat ""

let convert input =
    if Seq.length input % 4 <> 0 || Seq.length (Seq.head input) % 3 <> 0 then
        None
    else
        input
        |> Seq.chunkBySize 4
        |> Seq.map (fun elem -> convertSingleNum elem)
        |> String.concat ","
        |> Some
