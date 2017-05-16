#include "Utils.h"
#include "Chapter.h"
#include "vector.h"
#include <vector>
#include <string>

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

struct XX
{
	X a;
	X b;
};

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

int main()
{
	//chapter();

	//try_this();
	//try_this_2();

	ch_18_7_3();

	keep_window_open();

	return 0;
}