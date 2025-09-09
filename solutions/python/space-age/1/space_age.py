class SpaceAge:
    planets = ["mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune"]
    orbits = [0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132]

    def __init__(self, seconds):
        self.seconds = seconds

        for planet, orbit in zip(SpaceAge.planets, SpaceAge.orbits):
            setattr(self, "on_" + planet, lambda orbit=orbit: round(self.seconds / 31557600 / orbit, 2))