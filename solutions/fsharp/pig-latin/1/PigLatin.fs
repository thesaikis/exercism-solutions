module PigLatin

open System
open System.Text.RegularExpressions

let pairOfMatchGroup regStr word =
    let m = Regex.Match(word, regStr)

    match m.Success with
    | true -> Some(m.Groups.[1].Value, m.Groups.[2].Value)
    | _ -> None

let (|RuleOne|_|) (word: string) =
    match Regex.Match(word, @"^(?:[aeiou]|xr|yt).+").Success with
    | true -> Some word
    | _ -> None

let (|RuleTwo|_|) (word: string) =
    word |> pairOfMatchGroup @"^(qu|[^aeiou]+)(.+)"

let (|RuleThree|_|) (word: string) =
    word |> pairOfMatchGroup @"^([^aeiou]qu)(.+)"

let (|RuleFour|_|) (word: string) =
    word |> pairOfMatchGroup @"^([^aeiou]+)(y.*)"

let translateSingleWord (input: string) =
    match input with
    | RuleOne _ -> input + "ay"
    | RuleFour(start, rest)
    | RuleThree(start, rest)
    | RuleTwo(start, rest) -> rest + start + "ay"
    | _ -> input

let translate (input: string) =
    input.Split " " |> Array.map translateSingleWord |> String.concat " "
