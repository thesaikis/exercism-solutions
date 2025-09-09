(module
  ;; The name prefixed with $ is used to internally refer to functions via the call instruction
  ;; The string in the export instruction is the name of the export made available to the
  ;; embedding environment (in this case, Node.js). This is used by our test runner Jest.
  (func $squareOfSum (export "squareOfSum") (param $max i32) (result i32)
    (local $sum i32)
    (local.set $sum
      (i32.div_u
        (i32.mul
          (local.get $max)
          (i32.add (local.get $max) (i32.const 1)))
        (i32.const 2)))

    (i32.mul (local.get $sum) (local.get $sum))
  )

  (func $sumOfSquares (export "sumOfSquares") (param $max i32) (result i32)
    (i32.div_u
      (i32.mul
        (i32.mul
          (local.get $max)
          (i32.add (local.get $max) (i32.const 1)))
        (i32.add
          (i32.mul (local.get $max) (i32.const 2))
          (i32.const 1)))
      (i32.const 6))
  )

  (func (export "difference") (param $max i32) (result i32)
    (i32.sub
      (call $squareOfSum (local.get $max))
      (call $sumOfSquares (local.get $max)))
  )
)
