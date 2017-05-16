#pragma once
#include <iostream>
#include "vector.h"

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
	int last  = s.size() - 1;
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
}