#include <iostream>
#include "vector.h"
#include "Utils.h"

int main()
{
	//vector<int> v;

	//for (int i = 0; i < 10; ++i)
	//{
	//	v.push_back(i);
	//	std::cout << v[i] << " ";
	//}

	//std::cout << std::endl << std::endl;

	vector<char> cv;

	int i = 0;
	for (char c = 'A'; c <= 'Z'; ++c, ++i)
	{
		cv.push_back(c);
		std::cout << cv[i] << " ";
	}

	std::cout << std::endl;

	keep_window_open();

	return 0;
}