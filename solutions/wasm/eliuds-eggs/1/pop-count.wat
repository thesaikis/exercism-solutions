(module
  (func (export "eggCount") (param $number i32) (result i32)
    (local $count i32)

    (local.set $count (i32.const 0))

    (loop $continue
      (if (i32.gt_s (local.get $number) (i32.const 0))
        (then
          (local.set $count
            (i32.add
              (local.get $count)
              (i32.and
                (local.get $number)
                (i32.const 1)
              )
            )
          )

          (local.set $number
            (i32.shr_u (local.get $number) (i32.const 1))
          )

          (br $continue)
        )
      )
    )

    (return (local.get $count))
  )
)
