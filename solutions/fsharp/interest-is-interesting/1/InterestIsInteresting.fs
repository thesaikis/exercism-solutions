module InterestIsInteresting

let interestRate (balance: decimal): single =
   match balance with
   | b when b < 0m -> 3.213f
   | b when b < 1000m -> 0.5f
   | b when b < 5000m -> 1.621f
   | _ -> 2.475f

let interest (balance: decimal): decimal =
   let trueRate = interestRate balance / 100f |> decimal
   trueRate * balance |> decimal

let annualBalanceUpdate(balance: decimal): decimal =
   balance + interest balance

let amountToDonate(balance: decimal) (taxFreePercentage: float): int =
   match balance with
   | b when b < 0m -> 0
   | _ -> decimal taxFreePercentage / 100m * balance * 2m |> int
