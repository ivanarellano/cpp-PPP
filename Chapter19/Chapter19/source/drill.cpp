#include "work_selection.h"
#include <string>
#include <iostream>
#include <vector>
#include "Utils.h"

/// 1
template<typename T>
struct S {
	/// 2
	S(T val) : val{val} {}

	/// 5
	const T& get() const;
	/// 11
	T& get() { return val; }

	/// 9
	T set(const T& new_val) { val = new_val; }

	/// 10
	T& operator=(const T&);

/// 7
private:
	T val;
};

/// 6
template<typename T>
const T& S<T>::get() const 
{
	return val;
}

/// 10
template<typename T>
T& S<T>::operator=(const T& other) 
{
	val = other;
	return val;
}

/// 12
template<typename T>
std::istream& operator>>(std::istream& is, S<T>& ss) 
{
	T v;
	std::cin >> v;
	if (!is) return is;
	ss = v;
	return is;
}

template<typename T>
void read_val(T& v) 
{
	std::cout << "Enter a value\n"; 
	std::cin >> v;
}

/// 14
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) 
{
	os << "{ ";

	for (int i = 0; i < vec.size(); ++i) 
	{
		os << vec[i];
		if (i < vec.size() - 1) os << ",";
		os << " ";
	}

	os << "}";
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T> vec) 
{
	char c1;
	char c2;

	is >> c1;
	if (!is) return is;

	if (c1 != '{' ||) 
	{
		is.clear(ios_base::failbit);
		return is;
	}

	T tmp;
	while (cin >> tmp >> ch2 && ch2 != ',') 
	{
		vec.push_back(tmp);
	}

	if (ch2 != '}') 
	{
		is.clear(ios_base::failbit);
		return is;
	}

	vec.push_back(tmp);

	return is;
}

int Drill::main() 
{
	/// 3
	S<int> my_int = S<int>(1);
	S<char> my_char{ S<char>('a') };
	S<double> my_double(1.f);
	S<std::string> my_string = "my string";
	S<std::vector<int>> my_vect{ std::vector<int>{1, 3} };

	/// 4, then 8
	std::cout << my_int.get() << std::endl
		<< my_char.get() << std::endl
		<< my_double.get() << std::endl
		<< my_string.get() << std::endl;
	std::cout << my_vect.get()[0] << my_vect.get()[1] << std::endl;

	read_val(my_int);
	read_val(my_char);
	read_val(my_double);

	/// print all again
	std::cout << my_int.get() << std::endl
		<< my_char.get() << std::endl
		<< my_double.get() << std::endl;

	/// print vector
	std::cout << my_vect.get() << std::endl << std::endl;

	keep_window_open();
	return 0;
}

