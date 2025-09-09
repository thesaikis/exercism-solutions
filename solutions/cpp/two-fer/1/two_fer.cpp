#include "two_fer.h"

namespace two_fer
{
	const std::string two_fer(const std::string name) {
		return "One for " + name + ", one for me.";
	}

	const std::string two_fer() {
		return two_fer("you");
	}
} // namespace two_fer

