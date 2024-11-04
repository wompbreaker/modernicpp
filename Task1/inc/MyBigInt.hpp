#ifndef MY_BIG_INT_HPP
#define MY_BIG_INT_HPP

#include <cstdint>
#include <array>
#include <iostream>
#include <string.h>

struct MyBigInt {
public:
	MyBigInt();
	MyBigInt(const MyBigInt& other) = default;
	MyBigInt(int_least64_t n);
	MyBigInt& operator=(const MyBigInt& other);
	friend std::ostream& operator<<(std::ostream& os, const MyBigInt& n);
	friend MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs);
	static MyBigInt fromString(const char* str, size_t size);
	friend bool operator!=(const MyBigInt& lhs, const MyBigInt& rhs);
private:
	static constexpr int size{ 70 };
	std::array<int_least8_t, size> digits;
};

MyBigInt operator"" _mbi(const char* str);

#endif  /* MY_BIG_INT_HPP */
