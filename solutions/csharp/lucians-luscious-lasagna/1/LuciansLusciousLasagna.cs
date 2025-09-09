class Lasagna
{
    public int ExpectedMinutesInOven()
    {
        return 40;
    }

    public int RemainingMinutesInOven(int currentMinutesInOven)
    {
        return ExpectedMinutesInOven() - currentMinutesInOven;
    }

    // TODO: define the 'PreparationTimeInMinutes()' method
    public int PreparationTimeInMinutes(int layers)
    {
        return layers * 2;
    }

    // TODO: define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int layers, int currentMinutesInOven)
    {
        return currentMinutesInOven + PreparationTimeInMinutes(layers);
    }
}
