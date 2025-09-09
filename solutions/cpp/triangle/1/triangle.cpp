#include <stdexcept>

#include "triangle.h"

namespace triangle {

	flavor kind(double a, double b, double c) {
		if (a <= 0 || b <= 0 || c <= 0
			|| a + b < c || b + c < a || a + c < b)
			throw std::domain_error("invalid triangle");

		if (a == b && a == c && b == c)
			return flavor::equilateral;
		if (a != b && a != c && b != c)
			return flavor::scalene;
		return flavor::isosceles;
	}

}  // namespace triangle
