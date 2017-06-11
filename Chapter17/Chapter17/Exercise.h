#pragma once
#include <iostream>

void ex_1()
{
	int* a = new int{ 1 };
	std::cout << a << std::endl;
	std::cout << *a << std::endl;
}

void ex_2()
{
	// How many bytes in an 1) int 2) double 3) bool
	// int: 4 bytes = 32 bits
	// double 8 bytes = 64 bits
	// bool: 1 byte = 8 bits
	std::cout
		<< sizeof(int) << " "
		<< sizeof(double) << " "
		<< sizeof(bool) << ""
		<< std::endl;
}

// http://stackoverflow.com/questions/32063131/how-to-convert-constant-char-pointer-to-lower-case-in-c
// http://stackoverflow.com/questions/8459010/access-violation-writing-location-when-working-with-pointers-to-charvoid 
// https://softwareengineering.stackexchange.com/questions/294748/why-are-c-string-literals-read-only
void to_lower(char* s)
{
	while (*s != NULL)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 'a' - 'A'; // 32

		std::cout << *s << " " << s << std::endl;
		++s;
	}
}

// Find the first occurrence of the C-style string x in s
const char* findx(const char* s, const char* x)
{
	if (x == NULL) return NULL;

	for (int i = 0; s[i] != NULL; ++i)
	{
		if (s[i] == x[0])
		{
			for (int j = 1; x[j] != NULL; ++j)
			{
				if (s[i + j] != x[j]) break;           // did not match
				if (x[j + 1] == NULL) return &s[i];    // found full substring
				if (s[i + j + 1] == NULL) return NULL; // s ended before substring
			}
		}
	}

	return NULL;
}