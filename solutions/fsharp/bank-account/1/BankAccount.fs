module BankAccount

type BankAccount =
    { mutable balance: decimal
      isOpen: bool
      lock: obj }

let mkBankAccount () =
    { balance = 0.0m
      isOpen = false
      lock = obj () }

let openAccount account = { account with isOpen = true }

let closeAccount account = { account with isOpen = false }

let getBalance account =
    match account with
    | { balance = bal; isOpen = true } -> Some bal
    | _ -> None

let updateBalance change account =
    lock account.lock (fun () ->
        account.balance <- change + account.balance
        account)
