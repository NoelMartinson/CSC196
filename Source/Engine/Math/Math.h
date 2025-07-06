#pragma once
#include <algorithm>

namespace fox {
	namespace math {
		constexpr float pi = 3.1415926535f;
		constexpr float twoPi = 2 * pi;
		constexpr float haflPi = pi / 2;

		constexpr float radToDeg(float rad) { return rad * (180 / pi); }
		constexpr float degToRad(float deg) { return deg * (pi / 180); }

		using std::min;
		using std::max;
		using std::clamp;
	}
}