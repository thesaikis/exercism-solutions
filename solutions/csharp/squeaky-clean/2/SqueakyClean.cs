using System.Text;

public static class Identifier
{
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
