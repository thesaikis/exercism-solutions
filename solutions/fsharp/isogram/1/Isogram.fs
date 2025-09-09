module Isogram

open System

let isIsogram (str: string) =
    let lettersOfString = str.ToLower() |> Seq.filter Char.IsLetter

    lettersOfString
    |> Seq.distinct
    |> Seq.length
    |> (=) (Seq.length lettersOfString)
