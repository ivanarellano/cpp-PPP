#include "work_selection.h"
#include <string>
#include <iostream>
#include "Utils.h"

/// 1
template<typename T>
struct S {
	/// 2
	S(T val) : val{val} {}

	T val;

	/// 5
	T get() const;
};

template<typename T>
T S<T>::get() const {
	return val;
}

int Drill::main() {
	/// 3
	S<int> my_int = S<int>(1);
	S<char> my_char{ S<char>('a') };
	S<double> my_double(1.f);
	S<std::string> my_string = "my string";

	/// 4
	std::cout << my_int.val << std::endl
		<< my_char.val << std::endl
		<< my_double.val << std::endl
		<< my_string.val << std::endl;



	keep_window_open();
	return 0;
}

