using System;
using System.Linq;

public static class Bob
{
    public static string Response(string statement)
    {
        statement = statement.Trim();
        if (string.IsNullOrEmpty(statement)) return "Fine. Be that way!";

        var upperCase = statement.ToUpper();
        if (statement.Any(char.IsLetter))
        {
            if (statement.Equals(upperCase) && statement[statement.Length - 1] == '?')
                return "Calm down, I know what I'm doing!";
            else if (statement.Equals(upperCase))
                return "Whoa, chill out!";
            else if (statement[statement.Length - 1] == '?')
                return "Sure.";
        }
        else if (statement[statement.Length - 1] == '?')
            return "Sure.";

        return "Whatever.";
    }
}