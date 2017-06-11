#pragma once
#include <iostream>

void keep_window_open()
{
	char ch;
	std::cout << "Enter a key and enter to exit.";
	std::cin >> ch;
}

template<typename C>        // for all types C
void printout(const C& c)
{
	for (int i = 0; i < c.size(); ++i)
		std::cout << c[i] << std::endl;
}