module PizzaPricing

// TODO: please define the 'Pizza' discriminated union type
type Pizza =
    | Margherita
    | Caprese
    | Formaggio
    | ExtraSauce of Pizza
    | ExtraToppings of Pizza

let rec pizzaPrice (pizza: Pizza) : int =
    match pizza with
    | Margherita -> 7
    | Caprese -> 9
    | Formaggio -> 10
    | ExtraSauce p -> 1 + pizzaPrice p
    | ExtraToppings p -> 2 + pizzaPrice p

let orderPrice (pizzas: Pizza list) : int =
    let fee =
        match pizzas |> List.length with
        | 1 -> 3
        | 2 -> 2
        | _ -> 0

    pizzas |> List.fold (fun sum p -> sum + pizzaPrice p) fee
