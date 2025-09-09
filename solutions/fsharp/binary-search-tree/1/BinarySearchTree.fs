module BinarySearchTree

type Node =
    { value: int
      left: Node option
      right: Node option }

let left node = node.left

let right node = node.right

let data node = node.value

let create items =
    let rec insert (root: Node) (data: int) =
        let checkParent (value: int) (parent: Node option) =
            match parent with
            | Some p -> insert p value |> Some
            | None ->
                { value = value
                  left = None
                  right = None }
                |> Some

        if data <= root.value then
            { root with
                left = checkParent data root.left }
        else
            { root with
                right = checkParent data root.right }

    List.fold
        (fun acc num -> insert acc num)
        { value = (items |> List.head)
          left = None
          right = None }
        (items |> List.tail)

let sortedData node =
    let rec accumulate acc =
        function
        | Some { value = v; left = l; right = r } -> accumulate (v :: (accumulate acc r)) l
        | None -> acc

    accumulate [] (Some node)
