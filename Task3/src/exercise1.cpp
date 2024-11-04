#include <iostream>
#include <stdarg.h>

template<typename T, typename... Args>
T sum(T value, Args... args) {
	// Sum all the arguments and return the result
	T result = value;
	T arr[] = { args... };
	for (T i : arr) {
		result += i;
	}
	return result;
}

int main() {
	std::cout << sum(1, 2, 3, 4, 5) << "\n"; // Output: 15
	std::cout << sum(1.1, 2.2, 3.3) << "\n"; // Output: 6.6
	return 0;
}