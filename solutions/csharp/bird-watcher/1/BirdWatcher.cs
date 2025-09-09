using System;
using System.Linq;

class BirdCount
{
    private int[] birdsPerDay;

    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek() => new[] { 0, 2, 5, 3, 7, 8, 4 };

    public int Today() => birdsPerDay.Last();

    public void IncrementTodaysCount() => birdsPerDay[birdsPerDay.Length - 1]++;

    public bool HasDayWithoutBirds() => birdsPerDay.Any(day => day == 0);

    public int CountForFirstDays(int numberOfDays) => birdsPerDay[..numberOfDays].Sum();

    public int BusyDays() => birdsPerDay.Where(day => day >= 5).Count();
}
