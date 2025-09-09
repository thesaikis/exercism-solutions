module BookingUpForBeauty

// The following line is needed to use the DateTime type
open System

let schedule (appointmentDateDescription: string) : DateTime =
    appointmentDateDescription |> DateTime.Parse

let hasPassed (appointmentDate: DateTime) : bool = appointmentDate < DateTime.Now

let isAfternoonAppointment (appointmentDate: DateTime) : bool =
    match appointmentDate.Hour with
    | t when t >= 12 && t < 18 -> true
    | _ -> false

let description (appointmentDate: DateTime) : string =
    appointmentDate.ToString("M/d/yyyy h:mm:ss tt") |> sprintf "You have an appointment on %s."

let anniversaryDate () : DateTime = DateTime(DateTime.Now.Year, 9, 15)
