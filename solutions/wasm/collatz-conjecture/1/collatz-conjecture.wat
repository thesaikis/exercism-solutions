(module
  (func (export "steps") (param $number i32) (result i32)
    (local $steps i32)
    
    (if (i32.lt_s (local.get $number) (i32.const 1)) ;; check if $number is < 1
      (return (i32.const -1)) ;; return -1 as an error
    )

    (local.set $steps (i32.const 0))

    (loop $continue (block $break
      (br_if $break 
        (i32.eq (local.get $number) (i32.const 1)) ;; exit loop is $number is 1
      )

      (if (i32.rem_u (local.get $number) (i32.const 2)) ;; check if $number is odd (true if remainder is 1)
        (then
          (local.set $number ;; set $number to 3*n + 1
            (i32.add
              (i32.mul (i32.const 3) (local.get $number))
              (i32.const 1)
            )
          )
        )
        (else
          (local.set $number ;; set $number to n/2
            (i32.div_u (local.get $number) (i32.const 2))
          )
        )
      )

      (local.set $steps ;; increment $steps by 1
        (i32.add (local.get $steps) (i32.const 1))
      )

      br $continue
    ))

    (return (local.get $steps))
  )
)