raindrops <- function(number) {
  ans <- ""

  if (number %% 3 == 0)
    ans <- paste(ans, "Pling", sep='')
  if (number %% 5 == 0)
    ans <- paste(ans, "Plang", sep='')
  if (number %% 7 == 0)
    ans <- paste(ans, "Plong", sep='')

  if (ans == "")
    return (as.character(number))

  ans
}
