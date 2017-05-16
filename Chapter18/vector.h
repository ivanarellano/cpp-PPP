#pragma once
#include <initializer_list>
#include <algorithm>

class vector {
public:
	vector() : vector(0) {}

	explicit vector(int s) 
		: sz{ s }
		, elem{ new double[sz] }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}

	// size_t to int cast note: 
	// http://www.embedded.com/electronics-blogs/programming-pointers/4026076/Why-size-t-matters
	vector(std::initializer_list<double>lst) 
		: sz{ static_cast<int>(lst.size()) }
		, elem{ new double[sz] }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	// copy ctor
	vector(const vector& src) 
		: sz { src.sz }
		, elem{ new double[src.sz] }
	{
		std::copy(src.elem, src.elem + sz, elem);
	}

	// move ctor
	vector(vector&& src) 
		: sz{ src.sz }
		, elem {src.elem}
	{
		// make src the empty vector
		src.sz = 0;
		src.elem = nullptr;
	}

	~vector() { delete[] elem; }

	// copy assignment
	vector& operator=(const vector& src)
	{
		double* p_new_elem = new double[src.sz];            // allocate source sized space
		std::copy(src.elem, src.elem + src.sz, p_new_elem); // copy source elements into new elements allocation
		delete[] elem;                                      // delete the old/unused elements
		sz = src.sz;
		elem = p_new_elem;
		
		return *this;
	}

	// move assignment
	vector& operator=(vector&& src)
	{
		delete[] elem;
		sz = src.sz;
		elem = src.elem;
		src.sz = 0;
		src.elem = nullptr;

		return *this;
	}

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }
	int size() const { return sz; }

	double& operator[](int n) { return elem[n]; }      // non-const
	double operator[](int n) const { return elem[n]; } // const
private:
	int sz;
	double* elem;
};