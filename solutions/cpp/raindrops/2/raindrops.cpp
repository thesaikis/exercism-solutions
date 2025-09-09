#include <array>

#include "raindrops.h"

namespace raindrops {
	const std::array<std::pair<int, std::string>, 3> drops = { {
		{3, "Pling"},
		{5, "Plang"},
		{7, "Plong"}
	} };

	std::string convert(int num) {
		std::string result = "";

		for (auto &[factor, drop] : drops)
			if (num % factor == 0)
				result += drop;

		if (result == "")
			return std::to_string(num);
		return result;
	}
}  // namespace raindrops
