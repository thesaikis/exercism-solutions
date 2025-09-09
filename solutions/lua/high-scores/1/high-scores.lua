return function(scores)
    local obj = { data = scores[1] }

    function obj:scores()
        return self.data
    end

    function obj:latest()
        return self.data[#self.data]
    end

    function obj:personal_best()
        return math.max(table.unpack(self.data))
    end

    function obj:personal_top_three()
        local top = { table.unpack(self.data) }

        table.sort(top, function(a, b)
            return a > b
        end)

        return { table.unpack(top, 1, 3) }
    end

    return obj
end
