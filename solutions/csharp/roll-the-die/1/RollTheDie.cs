using System;

public class Player
{
    Random rand = new Random();
    
    public int RollDie()
    {
        return rand.Next(18) + 1;
    }

    public double GenerateSpellStrength()
    {
        return rand.NextDouble() * 100;
    }
}
