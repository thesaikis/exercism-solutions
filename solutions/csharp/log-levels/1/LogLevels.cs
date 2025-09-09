using System;

static class LogLine
{
    public static string Message(string logLine) => logLine.Split(' ', 2)[1].Trim();

    public static string LogLevel(string logLine)
    {
        int firstBracket = logLine.IndexOf('[');
        int secondBracket = logLine.IndexOf(']');
        return logLine.Substring(firstBracket + 1, secondBracket - firstBracket - 1).ToLower();
    }

    public static string Reformat(string logLine) => $"{Message(logLine)} ({LogLevel(logLine)})";
}
