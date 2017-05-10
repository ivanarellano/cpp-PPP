#pragma once

class vector {
public:
	vector(int s) : sz{ s }, elem{ new double[s] }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}

	~vector() { delete[] elem; }
private:
	int sz;
	double* elem;
};