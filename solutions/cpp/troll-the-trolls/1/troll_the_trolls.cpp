namespace hellmath {

	enum class AccountStatus {
		troll,
		guest,
		user,
		mod
	};

	enum class Action {
		read,
		write,
		remove
	};

	// the `display_post` function, that gets two arguments
	// of `AccountStatus` and returns a `bool`. The first argument is the status of
	// the poster, the second one is the status of the viewer.
	bool display_post(AccountStatus user1, AccountStatus user2) {
		return (user1 != AccountStatus::troll && user2 != AccountStatus::troll)
			|| (user1 == AccountStatus::troll && user2 == AccountStatus::troll);
	}

	// the `permission_check` function, that takes an
	// `Action` as a first argument and an `AccountStatus` to check against. It
	// should return a `bool`.
	bool permission_check(Action action, AccountStatus user) {
		switch (user) {
		case AccountStatus::troll:
		case AccountStatus::user:
			return action == Action::read || action == Action::write;
		case AccountStatus::guest:
			return action == Action::read;
		default: // Assume they are a mod, won't work if more account status are added.
			return true; // If more Actions are added that a mod CAN'T do, this won't work.
		}
	}

	// the `valid_player_combination` function that
	// checks if two players can join the same game. The function has two parameters
	// of type `AccountStatus` and returns a `bool`.
	bool valid_player_combination(AccountStatus user1, AccountStatus user2) {
		return !(user1 == AccountStatus::guest || user2 == AccountStatus::guest
			|| (user1 != user2 && (user1 == AccountStatus::troll || user2 == AccountStatus::troll)));
	}

	// the `has_priority` function that takes two
	// `AccountStatus` arguments and returns `true`, if and only if the first
	// account has a strictly higher priority than the second.
	bool has_priority(AccountStatus user1, AccountStatus user2) {
		return user1 > user2;
	}

}  // namespace hellmath