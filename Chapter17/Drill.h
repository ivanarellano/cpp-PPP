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

/* BEGIN DRILLS PART 2 */

void drill_p2_1_13()
{
	std::cout << "Drill p2 1-13" << std::endl;

	// 1.
	int* seven = new int{ 7 };
	int* p1 = seven;

	// 2.
	std::cout << *p1 << " " << *seven << std::endl;

	// 3.
	int seven_sz{ 7 };
	int* seven_arr = new int[seven_sz];
	for (int i = 0; i < seven_sz; ++i)
		seven_arr[i] = 1 + i;

	int* p2 = seven_arr;

	// 4.
	print_array(std::cout, p2, seven_sz);

	// 5.
	int* p3 = p2;

	// 6.
	p1 = p2;

	// 7.
	p3 = p2;

	// 8.
	std::cout << std::endl;
	print_array(std::cout, p1, 7);
	std::cout << std::endl;
	print_array(std::cout, p2, 7);
	std::cout << std::endl;

	// 9.
	delete[] seven;
	delete[] seven_arr;

	// 10.
	int ten_sz{ 10 };
	int* ten_arr = new int[ten_sz];
	for (int i = 0; i < ten_sz; ++i)
		ten_arr[i] = 2 * (i + 1);
	p1 = ten_arr;

	// 11.
	int* ten_2_arr = new int[ten_sz];
	p2 = ten_2_arr;

	std::cout << "p2 pointer: Before copying p1 into p2" << std::endl;
	print_array(std::cout, p2, 10);
	std::cout << std::endl;

	// 12.
	// MSVC Warning: http://stackoverflow.com/questions/42003997/c-array-copy-showing-errors-in-vc
	std::copy(p1, p1 + ten_sz, p2);

	std::cout << "p2 pointer: After copy " << std::endl;
	print_array(std::cout, p2, 10);
	std::cout << std::endl;

	// 13.
	std::vector<int> d13_1(10);
	for (unsigned int i = 0; i < d13_1.size(); ++i)
		d13_1[i] = 2 * (i + 1);

	std::vector<int> d13_2(10);
	d13_2 = d13_1;

	print_vector(d13_2);
	std::cout << std::endl;
}