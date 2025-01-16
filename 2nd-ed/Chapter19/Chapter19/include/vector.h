#pragma once
#include <initializer_list>
#include <algorithm>
#include <memory>

// For C++14
// template<Element T>  // for all types T, such that Element<T>() is true

struct out_of_range {};

template<typename T, typename A>
struct vector_base {
	A alloc;  // allocator
	T* elem;  // start of allocation
	int sz;
	int space;

	vector_base(const A& a, int n)
		: alloc{ a }
		, elem{ alloc.allocate(n) }
		, sz{ n }
		, space{ n }
	{
	}

	~vector_base() { alloc.deallocate(elem, space); }
};

template<typename Elem, typename A = std::allocator<Elem>> // requires Element<Elem>()
class vector {
public:
	vector() : sz{ 0 }, elem{ nullptr }, space{ 0 } {}

	explicit vector(int s) 
		: sz{ s }
		, elem{ new Elem[s] }
		, space{ s }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}

	// size_t to int cast note: 
	// http://www.embedded.com/electronics-blogs/programming-pointers/4026076/Why-size-t-matters
	vector(std::initializer_list<Elem> lst) 
		: sz{ static_cast<int>(lst.size()) }
		, elem{ new Elem[sz] }
		, space{ lst.size() }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	// copy ctor
	vector(const vector& src) 
		: sz { src.sz }
		, elem{ new Elem[src.sz] }
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

		Elem* p_new_elem = new Elem[src.sz];            // allocate source sized space
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

	// non-const
	Elem& at(int n)
	{
		if (n < 0 || n >= sz) throw out_of_range();
		return elem[n];
	}

	// const
	const Elem& at(int n) const { return at(n); }

	// non-const
	Elem& operator[](int n) { return elem[n]; }

	// const
	const Elem& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
	int capacity() const { return space; }

	void reserve(int newalloc)
	{
		if (newalloc <= space) return;
		Elem* new_elem = alloc.allocate(newalloc);
		for (int i = 0; i < sz; ++i) alloc.construct(&new_elem[i], elem[i]); // copy
		for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
		alloc.deallocate(elem, space);
		elem = new_elem;
		space = newalloc;
	}

	/*
	void reserve(int newalloc)
	{
		if (newalloc <= this->space) return;

		vector_base<Elem, A> b{ this->alloc.allocate(newalloc) }; // allocate new space
		std::uninitialized_copy(b.elem, &b.elem[this->sz], this->elem); // copy

		// destroy old
		for (int i = 0; i < this->sz; ++i) 
			this->alloc.destroy(&this->elem[i]);

		// swap representations
		std::swap<vector_base<Elem, A>>(*this, b);
	}
	*/

	// make the vector have newsize elements
	// initialize each new element with the default value 0.0
	void resize(int newsize, Elem val = Elem())
	{
		// pg 674 PPP - "try this"

		reserve(newsize);
		for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
		for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
		sz = newsize;
	}

	// increase vector size by one; initialize the new element with d
	void push_back(const Elem& val)
	{
		if (space == 0)
			reserve(8);
		else if (sz == space)
			reserve(space * 2);

		alloc.construct(&elem[sz], val);
		++sz;
	}
private:
	int sz;
	Elem* elem;
	int space;
	A alloc; // use allocate to handle memory for elements
};