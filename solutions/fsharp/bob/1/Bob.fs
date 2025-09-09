module Bob

open System

let response (input: string) : string =
    match input.Trim() with
    | r when r |> String.IsNullOrWhiteSpace -> "Fine. Be that way!"
    | r when
        r.EndsWith '?'
        && (r
            |> Seq.filter (fun c -> c |> Char.IsLetter)
            |> fun filtered -> not (Seq.isEmpty filtered) && Seq.forall Char.IsUpper filtered)
        ->
        "Calm down, I know what I'm doing!"
    | r when
        r
        |> Seq.filter (fun c -> c |> Char.IsLetter)
        |> fun filtered -> not (Seq.isEmpty filtered) && Seq.forall Char.IsUpper filtered
        ->
        "Whoa, chill out!"
    | r when r.EndsWith '?' -> "Sure."
    | _ -> "Whatever."
