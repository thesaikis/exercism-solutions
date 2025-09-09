local Hamming = {}

function Hamming.compute(a, b)
    if #a ~= #b then
        return -1
    end

    local dist = 0

    for i = 1, #a do
        if string.sub(a, i, i) ~= string.sub(b, i, i) then
            dist = dist + 1
        end
    end

    return dist
end

return Hamming
