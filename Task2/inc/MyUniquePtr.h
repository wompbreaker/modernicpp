#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

#include <iostream>
#define CUSTOM_MAKE_UNIQUE

template <typename T>
class MyUniquePtr
{
public:
	// Constructor
	explicit MyUniquePtr(T* ptr = nullptr) : m_ptr(ptr) {}

	// Destructor
	~MyUniquePtr() {
		delete m_ptr;
		std::cout << "Hi!" << std::endl;
	}

	// Move constructor
	MyUniquePtr(MyUniquePtr&& other) noexcept : m_ptr(other.m_ptr) {
		other.m_ptr = nullptr;
	}

	// Move assignment operator
	MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
		if (this != &other) {
			delete m_ptr;
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
		return *this;
	}

	// Delete copy constructor and copy assignment operator
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;

	// Dereference operator
	T& operator*() const {
		return *m_ptr;
	}

	// Arrow operator
	T* operator->() const {
		return m_ptr;
	}

	// Get the raw pointer
	T* get() const {
		return m_ptr;
	}

private:
	T* m_ptr;
};

#ifdef CUSTOM_MAKE_UNIQUE
namespace mup
{
	template <typename T, typename... Args>
	MyUniquePtr<T> make_unique(Args&&... args) {
		return MyUniquePtr<T>(new T(std::forward<Args>(args)...));
	}
}
#endif  /* CUSTOM_MAKE_UNIQUE */

#endif  /* MY_UNIQUE_PTR_H */
