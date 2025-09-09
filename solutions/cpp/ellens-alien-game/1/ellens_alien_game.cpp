namespace targets {
	class Alien {
	public:
		Alien(int x, int y) {
			x_coordinate = x;
			y_coordinate = y;
		}

		int get_health() {
			return health;
		}

		bool hit() {
			if (health > 0)
				health -= 1;
			return true;
		}

		bool is_alive() {
			return health > 0;
		}

		bool teleport(int x, int y) {
			x_coordinate = x;
			y_coordinate = y;
			return true;
		}

		bool collision_detection(Alien a) {
			return a.x_coordinate == x_coordinate && a.y_coordinate == y_coordinate;
		}

		int x_coordinate;
		int y_coordinate;
	private:
		int health{ 3 };
	};
}  // namespace targets