const std = @import("std");

pub fn isPangram(str: []const u8) bool {
    var set = std.bit_set.IntegerBitSet(26).initEmpty();

    for (str) |c| {
        if (!std.ascii.isAlphabetic(c)) continue;
        const lower = std.ascii.toLower(c);
        set.set(lower - 'a');
    }

    return set.count() == 26;
}
