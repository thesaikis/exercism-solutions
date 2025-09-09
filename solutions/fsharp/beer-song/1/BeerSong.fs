module BeerSong

let private createVerse bottles =
    match bottles with
    | 0 ->
        [ "No more bottles of beer on the wall, no more bottles of beer."
          "Go to the store and buy some more, 99 bottles of beer on the wall." ]
    | 1 ->
        [ "1 bottle of beer on the wall, 1 bottle of beer."
          "Take it down and pass it around, no more bottles of beer on the wall." ]
    | 2 ->
        [ "2 bottles of beer on the wall, 2 bottles of beer."
          "Take one down and pass it around, 1 bottle of beer on the wall." ]
    | _ ->
        [ $"{bottles} bottles of beer on the wall, {bottles} bottles of beer."
          $"Take one down and pass it around, {bottles - 1} bottles of beer on the wall." ]

let recite (startBottles: int) (takeDown: int) =
    List.init takeDown (fun n -> startBottles - n)
    |> List.map createVerse
    |> List.collect (fun l -> l @ [ "" ])
    |> List.rev
    |> List.tail
    |> List.rev
