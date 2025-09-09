#include "grains.h"

namespace grains {
	unsigned long long square(int square) {
		return 1ULL << (square - 1);
	}

	unsigned long long total() {
		return ~0ULL;
	}
}  // namespace grains
