using System;
using System.Linq;

public static class TelemetryBuffer
{
    public static byte[] ToBuffer(long reading)
    {
        var tempBuffer = reading switch
        {
            > UInt32.MaxValue => new byte[] { (byte)(256 - 8) }.Concat(BitConverter.GetBytes(reading)).ToArray(),
            > Int32.MaxValue => new byte[] { (byte)4 }.Concat(BitConverter.GetBytes((uint)reading)).ToArray(),
            > UInt16.MaxValue => new byte[] { (byte)(256 - 4) }.Concat(BitConverter.GetBytes((int)reading)).ToArray(),
            >= 0 => new byte[] { (byte)2 }.Concat(BitConverter.GetBytes((ushort)reading)).ToArray(),
            >= Int16.MinValue => new byte[] { (byte)(256 - 2) }.Concat(BitConverter.GetBytes((short)reading)).ToArray(),
            >= Int32.MinValue => new byte[] { (byte)(256 - 4) }.Concat(BitConverter.GetBytes((int)reading)).ToArray(),
            _ => new byte[] { (byte)(256 - 8) }.Concat(BitConverter.GetBytes(reading)).ToArray(),
        };

        return tempBuffer.Concat(new byte[9 - tempBuffer.Length]).ToArray();
    }

    public static long FromBuffer(byte[] buffer)
    {
        return buffer[0] switch
        {
            256 - 8 => BitConverter.ToInt64(buffer[1..]),
            4 => BitConverter.ToUInt32(buffer[1..]),
            256 - 4 => BitConverter.ToInt32(buffer[1..]),
            2 => BitConverter.ToUInt16(buffer[1..]),
            256 - 2 => BitConverter.ToInt16(buffer[1..]),
            _ => 0
        };
    }
}
