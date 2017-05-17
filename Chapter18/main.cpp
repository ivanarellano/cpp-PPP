#include "Utils.h"
#include "Chapter.h"
#include "Drill.h"

int factorial(int n)
{
	if (1 > n) throw std::exception("input must be greater than 1");

	int factor = 1;
	for (int i = 1; i <= n; ++i) factor *= i;
	return factor;
}

int main()
{
	//chapter();

	f(ga, 10);
	std::cout << std::endl << std::endl;

	int aa[10];

	for (int i = 0; i < 10; ++i)
		aa[i] = factorial(i + 1);
	
	f(aa, 10);

	std::cout << std::endl;
	keep_window_open();

	return 0;
}