module BirdWatcher

let lastWeek: int[] = [| 0; 2; 5; 3; 7; 8; 4 |]

let yesterday (counts: int[]) : int = counts[counts.Length - 2]

let total (counts: int[]) : int = counts |> Array.sum

let dayWithoutBirds (counts: int[]) : bool =
    Array.tryFind (fun num -> num = 0) counts <> None

let incrementTodaysCount (counts: int[]) : int[] =
    Array.append (Array.take (counts.Length - 1) counts) ([| Array.last counts + 1 |])

let unusualWeek (counts: int[]) : bool =
    let countsWithIdx = counts |> Array.zip [| 1 .. counts.Length |]

    let evenNoBirds =
        countsWithIdx |> Array.forall (fun (idx, count) -> idx % 2 = 1 || count = 0)

    let evenTenBirds =
        countsWithIdx |> Array.forall (fun (idx, count) -> idx % 2 = 1 || count = 10)

    let oddFiveBirds =
        countsWithIdx |> Array.forall (fun (idx, count) -> idx % 2 = 0 || count = 5)

    evenNoBirds || evenTenBirds || oddFiveBirds
