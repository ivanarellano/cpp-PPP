#pragma once

/*
- Allocate memory of a size suitable to hold an object of type T without initializing
- Construct an object of type T in uninitialized space
- Destroy an object of type T, thus returning its space to the unitialized state
- Deallocate uninitialized space of a size suitable for an object of type T

More reference: 
- The C++ Programming Language
- <memory>
- std::allocator http://en.cppreference.com/w/cpp/memory/allocator
*/

template<typename T>
class allocator
{
public:
	T* allocate(int n);               // allocate space for n objects of type T
	void deallocate(T* p, int n);     // deallocate n objects of type T starting at P

	void construct(T* p, const T& v); // construct a T with the value v in p
	void destroy(T* p);               // destroy the T in p
};