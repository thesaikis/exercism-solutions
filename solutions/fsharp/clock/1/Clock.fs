module Clock

type Clock = { hours: int; minutes: int }

let create (hours: int) (minutes: int) : Clock =
    let total = (hours * 60 + minutes) % (24 * 60)

    match total with
    | t when t < 0 ->
        { hours = ((t + (24 * 60)) / 60) % 24
          minutes = (t + (24 * 60)) % 60 }
    | _ ->
        { hours = (total / 60) % 24
          minutes = total % 60 }

let add minutes clock =
    create clock.hours (clock.minutes + minutes)

let subtract minutes clock = add -minutes clock

let display clock =
    sprintf "%02d:%02d" clock.hours clock.minutes
