local Darts = {}

function Darts.score(x, y)
    local dist = math.sqrt(x ^ 2 + y ^ 2)

    if dist <= 1 then
        return 10
    elseif dist <= 5 then
        return 5
    elseif dist <= 10 then
        return 1
    end

    return 0
end

return Darts
