#pragma once
#include <initializer_list>
#include <algorithm>

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[sz] }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}

	vector(std::initializer_list<double>lst) : sz{ lst.size() }, elem{ new double[sz] }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}

	vector(const vector& other) : sz { other.sz }, elem{ new double[other.sz] }
	{
		std::copy(other.elem, other.elem + sz, elem);
	}

	~vector() { delete[] elem; }

	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }
private:
	int sz;
	double* elem;
};