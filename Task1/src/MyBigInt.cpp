#include "MyBigInt.hpp"

MyBigInt::MyBigInt()
{
    // initialize all digits to 0
    for (int i = 0; i < size; i++)
        digits[i] = 0;
}

MyBigInt::MyBigInt(int_least64_t n)
{
    // initialize all digits to 0
    for (int i = 0; i < size; i++)
        digits[i] = 0;
    // fill digits from the end
    int i = size - 1;
    while (n > 0)
    {
        digits[i] = n % 10;
        n /= 10;
        i--;
    }
}

std::ostream& operator<<(std::ostream& os, const MyBigInt& n)
{
    // check if all digits are 0
    bool all_zero = true;
    for (int i = 0; i < n.size; i++)
    {
        if (n.digits[i] != 0)
        {
            all_zero = false;
            break;
        }
    }
    // if all digits are 0, print 0
    if (all_zero)
    {
        os << 0;
        return os;
    }

    // find first non-zero digit
    int i = 0;
    while (n.digits[i] == 0)
        i++;

    // print all digits leaving out leading zeros
    for (; i < n.size; i++)
        os << static_cast<int>(n.digits[i]);

    return os;
}

MyBigInt operator+(const MyBigInt& lhs, const MyBigInt& rhs)
{
	// add digits from the end
    MyBigInt result{ 0 };
    int carry = 0;
    for (int i = lhs.size - 1; i >= 0; i--)
    {
        int sum = lhs.digits[i] + rhs.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}

MyBigInt& MyBigInt::operator=(const MyBigInt& other)
{
    if (this != &other)
    {
        // copy all digits
        for (int i = 0; i < size; i++)
            digits[i] = other.digits[i];
    }
    return *this;
}

MyBigInt MyBigInt::fromString(const char* str, size_t size)
{
	// fill digits from the end
    MyBigInt result{ 0 };
    int i = MyBigInt::size - 1;
    for (int j = size - 1; j >= 0; j--)
    {
        result.digits[i] = str[j] - '0';
        i--;
    }
    return result;
}

bool operator!=(const MyBigInt& lhs, const MyBigInt& rhs)
{
	// compare all digits
    MyBigInt result{ 0 };
    for (int i = 0; i < lhs.size; i++)
    {
        if (lhs.digits[i] != rhs.digits[i])
            return true;
    }
    return false;
}

MyBigInt operator"" _mbi(const char* str)
{
	// create MyBigInt from string
    return MyBigInt::fromString(str, strlen(str));
}