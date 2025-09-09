using System;
using System.Collections.Generic;
using System.Linq;

public static class Languages
{
    public static List<string> NewList() => new List<string>();

    public static List<string> GetExistingLanguages() => new List<string>(new string[] { "C#", "Clojure", "Elm" });

    public static List<string> AddLanguage(List<string> languages, string language) => languages.Append(language).ToList();

    public static int CountLanguages(List<string> languages) => languages.Count;

    public static bool HasLanguage(List<string> languages, string language) => languages.Contains(language);

    public static List<string> ReverseList(List<string> languages) => languages.AsEnumerable().Reverse().ToList();

    public static bool IsExciting(List<string> languages) => languages.Count > 0 && (languages[0] == "C#" || (languages.Count >= 2 && languages.Count <= 3 && languages[1] == "C#"));

    public static List<string> RemoveLanguage(List<string> languages, string language) => languages.Remove(language) ? languages : languages;

    public static bool IsUnique(List<string> languages) => languages.Distinct().Count() == languages.Count;
}
