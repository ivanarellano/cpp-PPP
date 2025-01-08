#include "work_selection.h"
#include <iostream>
#include "vector.h"
#include "array.h"
#include "Utils.h"

int Chapter::main() 
{
	vector<int> v;

	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		std::cout << v[i] << " ";
	}

	std::cout << std::endl << std::endl;

	vector<char> cv;

	int i = 0;
	for (char c = 'A'; c <= 'Z'; ++c, ++i)
	{
		cv.push_back(c);
		std::cout << cv[i] << " ";
	}

	std::cout << std::endl << std::endl;

	array<double, 6> ad = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };

	for (int i = 0; i < ad.size(); ++i)
		std::cout << ad[i] << " ";

	std::cout << std::endl;

	double* p = ad.data();

	for (int i = 0; i < ad.size(); ++i, ++p)
		std::cout << *p << " ";

	std::cout << std::endl << std::endl;

	array<int, 3> ai;

	fill(ai, 1);
	printout(ai);

	std::cout << std::endl << std::endl;

	struct No_default {
		int i;
		No_default(int i) : i{ i } {}
	};

	vector<No_default> vn;
	vn.resize(10, No_default(2));

	for (int i = 0; i < vn.size(); ++i)
		std::cout << vn[i].i << " ";

	std::cout << std::endl;

	vector<int> vii;
	vii.push_back(1);
	int vii_index = -1;
	try {
		std::cout << v.at(vii_index) << std::endl;
	}
	catch (out_of_range) {
		std::cout << "bad index: " << vii_index << std::endl;
	}

	keep_window_open();
	return 0;
}