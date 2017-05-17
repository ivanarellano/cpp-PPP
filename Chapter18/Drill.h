#pragma once
#include <iostream>
#include <vector>

int ga[]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

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