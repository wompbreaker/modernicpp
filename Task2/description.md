# Task 2: Implementing `MyUniquePtr`

Implement type `MyUniquePtr` which will have the same functionalities as standard library type `unique_ptr`. In `main.cpp` file there is code that uses `unique_ptr`, and your type should be able to replace `unique_ptr` in that code (i.e. only implement functionalities used by that code).

## Instructions

1. In file `MyUniquePtr.h`, define class template `MyUniquePtr`.
2. With `#define` directive at the beginning of `main.cpp`, replace `unique_ptr` with `MyUniquePtr`.
3. After that, the code should compile and behave the same, whereas the commented block of code (“Errors”) should generate compile-time errors.
4. Pay attention to the `@TODO` comment at the end of function `main`.

## Note

Operator `->` is a special form of operator. It is always declared as a member function and it doesn’t accept any arguments. It should return a pointer to the type of field whose name corresponds to the right-hand side. Look it up on the Internet if you need more info.