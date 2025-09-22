function can_do_fast_attack(knight_awake)
    return !knight_awake
end

function can_spy(knight_awake, archer_awake, prisoner_awake)
    return knight_awake || archer_awake || prisoner_awake
end

function can_signal_prisoner(archer_awake, prisoner_awake)
    return !archer_awake && prisoner_awake
end

function can_free_prisoner(knight_awake, archer_awake, prisoner_awake, dog_present)
    return !archer_awake && (!knight_awake && prisoner_awake || dog_present)
end
