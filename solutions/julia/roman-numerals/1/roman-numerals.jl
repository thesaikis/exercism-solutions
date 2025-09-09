numerals = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

function to_roman(number)
    if number <= 0
        throw(ErrorException("error"))
    end
    
    idx = 1
    res = ""

    while number > 0
        while values[idx] <= number
            res *= numerals[idx]
            number = number - values[idx]
        end

        idx = idx + 1
    end

    return res
end
