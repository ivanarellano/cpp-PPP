// CppChapter8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "my.h"
#include <iostream>
#include "../../std_lib_facilities.h"

namespace X {
	int var;
	void print() { cout << var << endl; }
}

namespace Y {
	int var;
	void print() { cout << var << endl; }
}

namespace Z {
	int var;
	void print() { cout << var << endl;}
}

int main()
{
	foo = 7;
	print_foo();
	print(99);

	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}

	keep_window_open();
    return 0;
}

