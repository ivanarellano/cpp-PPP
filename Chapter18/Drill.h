#pragma once
#include <iostream>

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