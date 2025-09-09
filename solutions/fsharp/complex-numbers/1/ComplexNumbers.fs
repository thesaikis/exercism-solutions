module ComplexNumbers

type ComplexNumber = float * float

let create real imaginary = (real, imaginary)

let real = fst

let imaginary = snd

let mul ((a, b): ComplexNumber) ((c, d): ComplexNumber) = (a * c - b * d, b * c + a * d)

let add ((a, b): ComplexNumber) ((c, d): ComplexNumber) = (a + c, b + d)

let sub ((a, b): ComplexNumber) ((c, d): ComplexNumber) = (a - c, b - d)

let div ((a, b): ComplexNumber) ((c, d): ComplexNumber) =
    ((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d))

let conjugate ((a, b): ComplexNumber) = (a, -b)

let abs z = z |> mul (conjugate z) |> real |> sqrt

let exp ((a, b): ComplexNumber) = (exp a * cos b, exp a * sin b)
