defmodule RomanNumerals do
  @doc """
  Convert the number to a roman number.
  """
  @numerals ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
  @values [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

  @spec numeral(pos_integer) :: String.t()
  def numeral(number) do
    numeral(@numerals, @values, number, "")
  end

  def numeral([], [], number, str) do
    str
  end

  def numeral([first_num | tail_num], [first_val | tail_val], number, str) do
    if first_val > number do
      numeral(tail_num, tail_val, number, str)
    else
      numeral([first_num | tail_num], [first_val | tail_val], number - first_val, str <> first_num)
    end
  end
end
