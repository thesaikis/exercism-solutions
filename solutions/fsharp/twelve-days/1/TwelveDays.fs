module TwelveDays

let private gifts =
    [| "a Partridge in a Pear Tree."
       "two Turtle Doves, and"
       "three French Hens,"
       "four Calling Birds,"
       "five Gold Rings,"
       "six Geese-a-Laying,"
       "seven Swans-a-Swimming,"
       "eight Maids-a-Milking,"
       "nine Ladies Dancing,"
       "ten Lords-a-Leaping,"
       "eleven Pipers Piping,"
       "twelve Drummers Drumming," |]

let private ordinalNumbers =
    [| "first"
       "second"
       "third"
       "fourth"
       "fifth"
       "sixth"
       "seventh"
       "eighth"
       "ninth"
       "tenth"
       "eleventh"
       "twelfth" |]

let private reciteAllGifts startDay =
    gifts.[.. startDay - 1] |> Array.rev |> String.concat " "

let private reciteSingleDay day =
    $"On the {ordinalNumbers.[day - 1]} day of Christmas my true love gave to me: "
    + reciteAllGifts day


let recite start stop =
    [ start..stop ] |> Seq.map (fun day -> reciteSingleDay day) |> Seq.toList
