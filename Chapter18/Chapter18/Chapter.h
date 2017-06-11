#pragma once
#include <iostream>
#include <vector>
#include "vector.h"

struct X
{
	int val;

	void out(const std::string& s, int nv)
	{
		std::cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
	}

	X()
	{
		out("X", 0);
		val = 0;
	}

	X(int v)
	{
		val = v;
		out("X(int)", v);
	}

	X(const X& x)
	{
		val = x.val;
		out("X(X&)", x.val);
	}

	X& operator=(const X& a)
	{
		out("X::operator=()", a.val);
		val = a.val;
		return *this;
	}

	~X()
	{
		out("~X()", 0);
	}
};

struct XX
{
	X a;
	X b;
};

// read at most max-1 characters from is into buffer
std::istream& read_word(std::istream& is, char* buffer, int max)
{
	is.width(max);  // read at most max-1 chars in the next >>
	is >> buffer;   // read white-space terminated word,
					// add zero after the last char read into buffer
	return is;
}

bool is_palindrome(const std::string& s)
{
	int first = 0;
	int last = s.size() - 1;
	while (first < last)
	{
		if (s[first] != s[last]) return false;
		++first;
		--last;
	}

	return true;
}

// s points to the first character of an array of n characters
bool is_palindrome(const char s[], int n)
{
	int first = 0;
	int last = n - 1;
	while (first < last)
	{
		if (s[first] != s[last]) return false;
		++first;
		--last;
	}

	return true;
}

// first points to the first letter, last to the last letter
bool is_palindrome(const char* first, const char* last)
{
	while (first < last)
	{
		if (*first != *last) return false;
		++first;
		--last;
	}

	return true;
}

void ch_18_2()
{
	vector v1 = { 1, 2, 3 };
	vector v2(3);

	vector v3(3);
	v3.set(2, 2.2);
	vector v4 = v3;
}

void ch_18_3_3()
{
	// shallow copy
	int* p = new int{ 77 }; // initializes sequence of one int to 77
	int* q = p;             // copy the pointer p
	*p = 88;                // change the value of the int pointed to by p and q
	std::cout << "shallow copy" << std::endl
		<< "p: " << p << " " << *p << std::endl
		<< "q: " << q << " " << *q << std::endl;

	// deep copy
	int* a = new int{ 77 };
	int* b = new int{ *a };  // copy the value pointed to by a
	*a = 88;
	std::cout << "deep copy" << std::endl
		<< "a: " << a << " " << *a << std::endl
		<< "b: " << b << " " << *b << std::endl;
}

void ch_18_5_1(const vector& cv)
{
	double d = cv[0];
	//cv[0] = 2.0;		// error: cv is const, cannot write
}

void ch_18_7_1()
{
	for (std::string s; std::cin >> s;)
	{
		std::cout << s << " is";
		if (!is_palindrome(s)) std::cout << " not";
		std::cout << " a palindrome" << std::endl;
	}
}

void ch_18_7_2()
{
	constexpr int max{ 128 };
	for (char s[max]; read_word(std::cin, s, max);)
	{
		std::cout << s << " is";
		if (!is_palindrome(s, strlen(s))) std::cout << " not";
		std::cout << " a palindrome" << std::endl;
	}
}

void ch_18_7_3()
{
	for (std::string s; std::cin >> s;)
	{
		std::cout << s << " is";
		if (!is_palindrome(&s[0], &s[s.size() - 1])) std::cout << " not";
		std::cout << " a palindrome" << std::endl;
	}
}

//X glob(2);
//X glob{ 3 };

X copy(X a) { return a; }

X copy2(X a)
{
	X aa{ a }; // copy assign
	return aa;
}

X& ref_to(X& a) { return a; }

X* make(int i)
{
	X a(i);
	return new X(a);
}

void try_this()
{
	X loc{ 4 };          // X(int) .. ~X()
	std::cout << std::endl;

	X loc2{ loc };       // X(X&) .. ~X()
	std::cout << std::endl;

	loc = X{ 5 };        // X(int) .. X::operator= .. ~X()
	std::cout << std::endl;

	loc2 = copy(loc);    // X(X&) x2 .. ~X() x2
	std::cout << std::endl;

	loc2 = copy2(loc);   // X(X&) x3 .. ~X() x3
	std::cout << std::endl;

	X loc3{ 6 };         // X(int) .. ~X()
	std::cout << std::endl;

	X& r = ref_to(loc3); // no ctor or dtor are called
	std::cout << std::endl;

	delete make(7);      // X(int) .. X(&) .. ~X() .. ~X()
	std::cout << std::endl;

	delete make(8);      // X(int) .. X(&) .. ~X() .. ~X()
	std::cout << std::endl;

	std::vector<X> v(4); // X(int) x4, ~X() x4
	std::cout << std::endl;

	XX loc4;             // X(int) x2
	std::cout << std::endl;

	X* p = new X{ 9 };   // X(int)
	std::cout << std::endl;

	delete p;            // ~X()
	std::cout << std::endl;

	X* pp = new X[5];    // X(int) x5
	std::cout << std::endl;

	delete[] pp;        // ~X() x5
	std::cout << std::endl;
}

void try_this_2()
{
	vector v{ 10 };
	//double x = *v[2];
	//v[3] = x; // error: expression must be a modifiable lvalue

	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i;
		std::cout << v[i] << std::endl;
	}
}

// Test implicit constructor vector::vector(int)
void f(const vector& v) {}

void chapter()
{
	//f(10);

	ch_18_2();
	std::cout << std::endl;

	ch_18_3_3();
	std::cout << std::endl;

	ch_18_5_1(vector{ 0 });
	std::cout << std::endl;

	ch_18_7_1();
	std::cout << std::endl;

	ch_18_7_2();
	std::cout << std::endl;

	ch_18_7_3();
	std::cout << std::endl;

	try_this();
	std::cout << std::endl;

	try_this_2();
	std::cout << std::endl;
}