using System;
using System.Linq;
using System.Text;

public static class Identifier
{
    public static string SClean(string identifier)
    {
        var builder = new StringBuilder(identifier);

        builder.Replace(' ', '_');
        builder.Replace("\0", "CTRL");

        for (int i = 1; i < builder.Length; i++)
        {
            if (builder[i - 1] == '-')
            {
                builder[i] = char.ToUpper(builder[i]);
            }
        }

        for (int i = 0; i < builder.Length; i++)
        {
            if (!char.IsLetter(builder[i]) && builder[i] != '_' || (builder[i] >= '\u03b1' && builder[i] <= '\u03c9'))
            {
                builder.Remove(i, 1);
                i--;
            }
        }

        return builder.ToString();
    }

    public static string Clean(string identifier)
    {
        var builder = new StringBuilder();
        var mustCaps = false;

        foreach (char c in identifier.Replace(' ', '_').Replace("\0", "CTRL"))
        {
            if (c >= '\u03b1' && c <= '\u03c9') continue;
            if (c == '-') mustCaps = true;
            if (char.IsLetter(c) || c == '_')
            {
                builder.Append(mustCaps ? char.ToUpper(c) : c);
                mustCaps = false;
            }
        }

        return builder.ToString();
    }
}
