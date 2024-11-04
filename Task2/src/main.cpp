#include <memory>
#include "MyUniquePtr.h"

#include <iostream>
#define myUP MyUniquePtr

struct MyClass {
	MyClass(int a, int b, int c) : x(a), y(b), z(c) {}
	int x, y, z;
};

void foo(const MyClass& x) {
	std::cout << x.x;
}

void bar(const MyClass* x) {
	std::cout << x->y;
}

myUP<MyClass> make_object_up() {
	#ifdef CUSTOM_MAKE_UNIQUE
		return mup::make_unique<MyClass>(1, 2, 3);
	#else
		return myUP<MyClass>(new MyClass(1, 2, 3));
	#endif  /* CUSTOM_MAKE_UNIQUE */
}

int main()
{
	myUP<MyClass> p;
	p = make_object_up();
	std::cout << p.get() << "\n";
	foo(*p);
	bar(p.get());
	std::cout << p->z << "\n";

	// Errors: disallow this. Uncomment to see the error.
	// myUP<MyClass> q{p};
	// myUP<MyClass> r;
	// r = p;

	// @TODO: print "Hi!" from destructor
	return 0;
}
