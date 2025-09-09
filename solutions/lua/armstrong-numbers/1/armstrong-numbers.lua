local ArmstrongNumbers = {}

function ArmstrongNumbers.is_armstrong_number(number)
    local sum = 0
    local n = number
    local digits = math.floor(math.log(number, 10)) + 1

    while n > 0 do
        sum = sum + (n % 10) ^ digits
        n = math.floor(n / 10)
    end

    return number == sum
end

return ArmstrongNumbers
