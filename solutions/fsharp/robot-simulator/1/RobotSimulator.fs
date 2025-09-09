module RobotSimulator

type Direction =
    | North
    | East
    | South
    | West

type Position = int * int

type Robot =
    { Direction: Direction
      Position: Position }

let private directionToInt direction =
    match direction with
    | North -> 0
    | East -> 1
    | South -> 2
    | West -> 3

let private intToDirection i =
    match i with
    | 0 -> North
    | 1 -> East
    | 2 -> South
    | _ -> West

let private changeDir direction mov =
    let directionInt = directionToInt direction
    let newDirectionInt = (directionInt + (mov + 4)) % 4
    intToDirection newDirectionInt

let create direction position =
    { Direction = direction
      Position = position }

let private updatePosition (x, y) direction =
    match direction with
    | North -> (x, y + 1)
    | East -> (x + 1, y)
    | South -> (x, y - 1)
    | West -> (x - 1, y)

let rec moveHelper (instructions: char list) robot =
    match instructions with
    | [] -> robot
    | c :: rest ->
        let newRobot =
            match c with
            | 'R' ->
                { robot with
                    Direction = changeDir robot.Direction 1 }
            | 'L' ->
                { robot with
                    Direction = changeDir robot.Direction -1 }
            | _ ->
                { robot with
                    Position = updatePosition robot.Position robot.Direction }

        moveHelper rest newRobot

let move (instructions: string) robot =
    moveHelper (instructions |> List.ofSeq) robot
