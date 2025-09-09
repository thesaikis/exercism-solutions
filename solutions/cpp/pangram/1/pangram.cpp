#include <set>

#include "pangram.h"

namespace pangram {
	bool is_pangram(std::string input) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (input.find(c) == std::string::npos && input.find(c - 32) == std::string::npos)
				return false;
		}

		return true;
	}
}  // namespace pangram
