module LuciansLusciousLasagna

let expectedMinutesInOven = 40

let remainingMinutesInOven curTime = expectedMinutesInOven - curTime

let preparationTimeInMinutes layers = layers * 2

let elapsedTimeInMinutes layers curTime =
    preparationTimeInMinutes layers + curTime
