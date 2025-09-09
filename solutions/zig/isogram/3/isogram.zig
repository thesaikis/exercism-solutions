const std = @import("std");

pub fn isIsogram(str: []const u8) bool {
    var charsFound: [26]bool = [_]bool{false} ** 26;

    for (str) |char| {
        const lowChar: u8 = std.ascii.toLower(char);
        if (!std.ascii.isAlphabetic(lowChar)) continue;
        if (charsFound[lowChar - 'a']) return false;
        charsFound[lowChar - 'a'] = true;
    }

    return true;
}
