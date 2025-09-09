local PopCount = {}

function PopCount.egg_count(number)
    local count = 0

    while number > 0 do
        if number & 1 == 1 then
            count = count + 1
        end

        number = number >> 1
    end

    return count
end

return PopCount
