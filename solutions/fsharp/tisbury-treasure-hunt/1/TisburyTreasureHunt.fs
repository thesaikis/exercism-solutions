module TisburyTreasureHunt

open System

let getCoordinate (line: string * string) : string = snd line

let convertCoordinate (coordinate: string) : int * char =
    (coordinate |> Seq.head |> Char.GetNumericValue |> int, coordinate |> Seq.last)

let compareRecords (azarasData: string * string) (ruisData: string * (int * char) * string) : bool =
    match ruisData with
    | (_, coord, _) -> azarasData |> snd |> convertCoordinate = coord

let createRecord
    (azarasData: string * string)
    (ruisData: string * (int * char) * string)
    : (string * string * string * string) =
    let (loc, _, quad) = ruisData

    match compareRecords azarasData ruisData with
    | true -> (azarasData |> snd, loc, quad, azarasData |> fst)
    | _ -> ("", "", "", "")
