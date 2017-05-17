#pragma once
#include <iostream>
#include <vector>

int ga[]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

int factorial(int n)
{
	if (1 > n) throw std::exception("input must be greater than 1");

	int factor = 1;
	for (int i = 1; i <= n; ++i) factor *= i;
	return factor;
}

void f(int arr[], int sz)
{
	int la[10];

	for (int i = 0; i < 10; ++i)
	{
		la[i] = ga[i];
		std::cout << la[i] << " ";
	}

	std::cout << std::endl;

	int* p = new int[sz];

	for (int i = 0; i < sz; ++i)
	{
		p[i] = arr[i];
		std::cout << p[i] << " ";
	}

	delete[] p;
}

std::vector<int> gv{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(const std::vector<int>& v)
{
	std::vector<int> lv(v.size());
	lv = gv;

	for (auto i : lv)
		std::cout << i << " ";

	std::cout << std::endl;

	std::vector<int> lv2{ v };

	for (auto i : lv2)
		std::cout << i << " ";
}

void drill()
{
	std::cout << "Start array drill" << std::endl;

	f(ga, 10);
	std::cout << std::endl << std::endl;

	int aa[10];

	for (int i = 0; i < 10; ++i)
		aa[i] = factorial(i + 1);

	f(aa, 10);

	std::cout
		<< std::endl << std::endl
		<< "Start vector drill"
		<< std::endl;

	f(gv);
	std::cout << std::endl << std::endl;

	std::vector<int> vv(10);
	int i = 0;
	for (auto it = vv.begin(); it != vv.end(); ++it, ++i)
		*it = factorial(i + 1);

	f(vv);

	std::cout << std::endl;
}