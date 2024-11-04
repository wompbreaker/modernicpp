#include <iostream>
#include <stdarg.h>

template<typename T, typename... Args>
T min(T value, Args... args) {
	// Find the minimum value among the arguments
	T result = value;
	T arr[] = { args... };
	for (T i : arr) {
		if (i < result) {
			result = i;
		}
	}
	return result;
}

int main() {
	std::cout << min(1, 2, 3, 4, 5) << "\n"; // Output: 1
	std::cout << min(1.1, 2.2, 3.3) << "\n"; // Output: 1.1
	std::cout << min(10, 9, 8, 7, 6) << "\n"; // Output: 6
	std::cout << min(-1, -2, -3, -4, -5) << "\n"; // Output: -5
	std::cout << min(5, 4, 3, 2, 1) << "\n"; // Output: 1
	std::cout << min(0.5, 0.4, 0.3, 0.2, 0.1) << "\n"; // Output: 0.1
	std::cout << min(100, 200, 300, 400, 500) << "\n"; // Output: 100
	std::cout << min(3.14, 2.71, 1.61) << "\n"; // Output: 1.61
	std::cout << min(-10, 0, 10) << "\n"; // Output: -10
	std::cout << min(42) << "\n"; // Output: 42
	std::cout << min(0, 0, 0, 0) << "\n"; // Output: 0
	return 0;
}