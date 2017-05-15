#pragma once
#include <iostream>
#include <vector>

void drill_1_3()
{
	std::cout << "Drill 1-3" << std::endl;
	// 1.
	int* arr = new int[10];  // 10 ints default initialized

	// 2.
	for (int i = 0; i < 10; ++i)
		std::cout << arr[i] << std::endl;

	// 3.
	delete[] arr;
} 

void print_array10(std::ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << a[i] << std::endl;
}

void drill_4()
{
	std::cout << "Drill 4" << std::endl;
	// 4.
	int* arr = new int[10];
	print_array10(std::cout, arr);
	delete[] arr;
}

void drill_5()
{
	std::cout << "Drill 5" << std::endl;
	// 5.
	int* arr = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = 100 + i;
		std::cout << arr[i] << std::endl;
	}
	delete[] arr;
}

void drill_6()
{
	std::cout << "Drill 6" << std::endl;
	int* arr = new int[11];
	for (int i = 0; i < 11; ++i)
	{
		arr[i] = 100 + i;
		std::cout << arr[i] << std::endl;
	}
	delete[] arr;
}

void print_array(std::ostream& os, int* a, int sz)
{
	for (int i = 0; i < sz; ++i)
		os << a[i] << std::endl;
}

void drill_7()
{
	std::cout << "Drill 7" << std::endl;
	int sz = 11;
	int* arr = new int[sz];
	print_array(std::cout, arr, sz);
	delete[] arr;
}

void drill_8()
{
	std::cout << "Drill 8" << std::endl;
	int sz{ 20 };
	int* arr = new int[sz];
	for (int i = 0; i < sz; ++i)
	{
		arr[i] = 100 + i;
		std::cout << arr[i] << std::endl;
	}
	delete[] arr;
}

// drill_9: delete the arrays from free store

void print_vector(const std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << std::endl;
}

void drill_10()
{
	std::cout << "Drill 10" << std::endl;
	std::vector<int> d5(10);
	std::vector<int> d6(11);
	std::vector<int> d8(20);

	for (unsigned int i = 0; i < d5.size(); ++i)
		d5[i] = 100 + i;

	int i = 0;
	for (auto it = d6.begin(); it != d6.end(); ++it)
	{
		*it = 100 + i;
		++i;
	}

	i = 0;
	for (std::vector<int>::iterator it = d8.begin(); it != d8.end(); ++it)
	{
		*it = 100 + i;
		++i;
	}

	std::cout << "Print std::vector<int> d5(10)" << std::endl;
	print_vector(d5);
	std::cout << "Print std::vector<int> d6(11)" << std::endl;
	print_vector(d6);
	std::cout << "Print std::vector<int> d8(20)" << std::endl;
	print_vector(d8);
}