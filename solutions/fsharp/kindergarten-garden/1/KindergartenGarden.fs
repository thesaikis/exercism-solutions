module KindergartenGarden

type Plant =
    | Grass
    | Clover
    | Radishes
    | Violets

let plants (diagram: string) (student: string) =
    let idx = int student.[0] - int 'A'

    let map char =
        match char with
        | 'G' -> Grass
        | 'C' -> Clover
        | 'R' -> Radishes
        | _ -> Violets

    let result =
        diagram.Split('\n')
        |> Seq.collect (fun line -> line.[idx * 2 .. idx * 2 + 1] |> Seq.map map)

    result |> List.ofSeq
