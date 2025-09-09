using System;

class RemoteControlCar
{
    private int speed;
    private int batteryDrain;
    private int battery;
    private int distanceDriven;

    public RemoteControlCar(int speed, int batteryDrain)
    {
        this.speed = speed;
        this.batteryDrain = batteryDrain;
        this.battery = 100;
    }

    public bool BatteryDrained() => battery - batteryDrain < 0;
    public int DistanceDriven() => distanceDriven;

    public void Drive()
    {
        if (BatteryDrained()) return;

        distanceDriven += speed;
        battery -= batteryDrain;
    }

    public static RemoteControlCar Nitro() => new RemoteControlCar(50, 4);
}

class RaceTrack
{
    private int distance;

    public RaceTrack(int distance)
    {
        this.distance = distance;
    }

    public bool TryFinishTrack(RemoteControlCar car)
    {
        while (!car.BatteryDrained())
        {
            car.Drive();
        }

        return car.DistanceDriven() >= distance;
    }
}
