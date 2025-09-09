using System;

class RemoteControlCar
{
    private int _metersDriven;
    private int _batteryPercentage = 100;

    public static RemoteControlCar Buy() => new();

    public string DistanceDisplay() => $"Driven {_metersDriven} meters";

    public string BatteryDisplay()
    {
        if (_batteryPercentage == 0)
            return "Battery empty";
        return $"Battery at {_batteryPercentage}%";
    }

    public void Drive()
    {
        if (_batteryPercentage == 0) return;

        _metersDriven += 20;
        _batteryPercentage -= 1;
    }
}
