#pragma once
#include <iostream>
#include "Link.h"
#include "GoodLink.h"

void keep_window_open()
{
	char ch;
	std::cout << "Enter a key and enter to exit.";
	std::cin >> ch;
}

void print_all(Link* p)
{
	std::cout << "{";

	while (p) {
		std::cout << p->value;
		if (p = p->succ) std::cout << ", ";
	}

	std::cout << "}";
}

void print_all(GoodLink* p)
{
	std::cout << "{";

	while (p) {
		std::cout << p->value;
		if (p = p->next()) std::cout << ", ";
	}

	std::cout << "}";
}