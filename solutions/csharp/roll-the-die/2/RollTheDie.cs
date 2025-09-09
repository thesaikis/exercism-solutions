using System;

public class Player
{
    Random rand = new Random();
    
    public int RollDie() => rand.Next(18) + 1;

    public double GenerateSpellStrength() => rand.NextDouble() * 100;
}
