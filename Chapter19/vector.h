#pragma once
#include <initializer_list>
#include <algorithm>

template<typename T>
class vector {
public:
	vector() : sz{ 0 }, elem{ nullptr }, space{ 0 } {}

	explicit vector(int s) 
		: sz{ s }
		, elem{ new T[s] }
		, space{ s }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}

	// size_t to int cast note: 
	// http://www.embedded.com/electronics-blogs/programming-pointers/4026076/Why-size-t-matters
	vector(std::initializer_list<T> lst) 
		: sz{ static_cast<int>(lst.size()) }
		, elem{ new T[sz] }
		, space{ lst.size() }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	// copy ctor
	vector(const vector& src) 
		: sz { src.sz }
		, elem{ new T[src.sz] }
		, space{ src.space }
	{
		std::copy(src.elem, src.elem + sz, elem);
	}

	// move ctor
	vector(vector&& src) 
		: sz{ src.sz }
		, elem{ src.elem }
		, space{ src.space }
	{
		// make src the empty vector
		src.sz = 0;
		src.space = 0;
		src.elem = nullptr;
	}

	~vector() { delete[] elem; }

	// copy assignment
	vector& operator=(const vector& src)
	{
		if (this == &src) return *this;  // self-assignment, no work needed

		if (src.sz <= space)
		{
			for (int i = 0; i < sz; ++i) elem[i] = src.elem[i];
			sz = src.sz;
			return *this;
		}

		T* p_new_elem = new T[src.sz];            // allocate source sized space
		std::copy(src.elem, src.elem + src.sz, p_new_elem); // copy source elements into new elements allocation
		delete[] elem;                                      // delete the old/unused elements
		sz = src.sz;
		space = src.sz;
		elem = p_new_elem;
		
		return *this;
	}

	// move assignment
	vector& operator=(vector&& src)
	{
		delete[] elem;
		sz = src.sz;
		space = src.sz;
		elem = src.elem;
		src.sz = 0;
		src.space = 0;
		src.elem = nullptr;

		return *this;
	}

	T& operator[](int n) { return elem[n]; }             // non-const
	const T& operator[](int n) const { return elem[n]; } // const

	int size() const { return sz; }
	int capacity() const { return space; }

	void reserve(int newalloc)
	{
		if (newalloc <= space) return;
		T* new_elem = new T[newalloc];
		for (int i = 0; i < sz; ++i) new_elem[i] = elem[i];
		delete[] elem;
		elem = new_elem;
		space = newalloc;
	}

	// make the vector have newsize elements
	// initialize each new element with the default value 0.0
	void resize(int newsize)
	{
		// pg 674 PPP - "try this"

		reserve(newsize);
		for (int i = sz; i < newsize; ++i) elem[i] = 0;
		sz = newsize;
	}

	// increase vector size by one; initialize the new element with d
	void push_back(const T& d)
	{
		if (space == 0)
			reserve(8);
		else if (sz == space)
			reserve(space * 2);

		elem[sz] = d;
		++sz;
	}
private:
	int sz;
	T* elem;
	int space;
};