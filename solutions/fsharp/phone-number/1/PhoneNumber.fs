module PhoneNumber

let private secondCheck input =
    if Seq.item 0 input < '2' then
        Error ("area code cannot start with " + if Seq.item 0 input = '1' then "one" else "zero")
    elif Seq.item 3 input < '2' then
        Error ("exchange code cannot start with " + if Seq.item 3 input = '1' then "one" else "zero")
    else 
        System.String(input |> Seq.toArray) |> System.UInt64.Parse |> Ok


let clean input =
    let onlyNumbers = Seq.filter System.Char.IsDigit input

    if Seq.exists System.Char.IsLetter input then
        Error "letters not permitted"
    elif Seq.exists (fun c -> set ['@'; ':'; '!'] |> Set.contains c) input then
        Error "punctuations not permitted"
    elif Seq.length onlyNumbers < 10 then
        Error "incorrect number of digits"
    elif Seq.length onlyNumbers = 11 && Seq.head onlyNumbers <> '1' then
        Error "11 digits must start with 1"
    elif Seq.length onlyNumbers > 11 then
        Error "more than 11 digits"
    elif Seq.length onlyNumbers = 11 then
        onlyNumbers |> Seq.tail |> secondCheck
    else
        onlyNumbers |> secondCheck