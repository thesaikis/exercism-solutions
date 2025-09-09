module GradeSchool

type School = Map<int, string list>

let empty: School = Map.empty

let add (student: string) (grade: int) (school: School) : School =
    if
        school
        |> Map.exists (fun _ students -> students |> List.exists (fun s -> s = student))
    then
        school
    else
        match school |> Map.tryFind grade with
        | Some l -> school |> Map.add grade (student :: l)
        | None -> Map.add grade [ student ] school

let roster (school: School) : string list =
    school
    |> Map.fold (fun acc _ students -> students |> List.sort |> List.append acc) []

let grade (number: int) (school: School) : string list =
    match school |> Map.tryFind number with
    | Some l -> l |> List.sort
    | None -> []
