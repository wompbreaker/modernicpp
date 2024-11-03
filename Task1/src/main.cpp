#include "MyBigInt.hpp"

#include <iostream>

static MyBigInt fibo(int n)
{
	// calculate n-th Fibonacci number
	MyBigInt a{ 0 };
	MyBigInt b{ 1 };
	if (n == 0) return a;
	if (n == 1) return b;

	MyBigInt c{ 0 };
	for (int i = 2; i <= n; i++)
	{
 		c = a + b;
 		a = b;
 		b = c;
	}
	return c;
}

int main()
{
	MyBigInt k{ 7 };
	std::cout << "k = " << k << "\n";
	k = fibo(9);
	std::cout << "9th fibonacci number: " << k << "\n";
	k = k + 5;
	std::cout << "k + 5 = " << k << "\n";
	k = 7 + fibo(11);
	std::cout << "11th fibonacci number + 7: " << k << "\n";
	k = 13_mbi;
	std::cout << "13_mbi = " << k << "\n";
	MyBigInt l = fibo(300);
	std::cout << "300th fibonacci number: " << l << "\n";
	if (l != 222232244629420445529739893461909967206666939096499764990979600_mbi)
	{
		std::cout << "Error!" << "\n";
		return 1;
	}
	else
		std::cout << "OK!" << "\n";
	return 0;
}
