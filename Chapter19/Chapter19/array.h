#pragma once
#include <iostream>

template<typename T, int N>
struct array
{
	T elem[N];

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	T* data() { return elem; }
	const T* data() const { return elem; }

	int size() const { return N; }
};


template<typename T, int N>
void fill(array<T, N>& b, const T& val)
{
	for (int i = 0; i < N; ++i)
		b[i] = val;
}