// CalculatorApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};


int main()
{
	cout << "Please enter expression (we can handle + and -, *, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";

	keep_window_open();

	//int lval = 0;
	//int rval;
	//cin >> lval;	// read leftmost operand
	//if (!cin) error("no first operand");

	//for (char op; cin >> op; ) {	// read operator and right-hand operand
	//								// repeatedly
	//	if (op != 'x') cin >> rval;
	//	if (!cin) error("no second operand");

	//	switch (op) {
	//	case '+':
	//		lval += rval;
	//		break;
	//	case '-':
	//		lval -= rval;
	//		break;
	//	case '*':
	//		lval *= rval;
	//		break;
	//	case '/':
	//		lval /= rval;
	//		break;
	//	default:
	//		cout << "Result: " << lval << "\n";
	//		keep_window_open();
	//		return 0;
	//	}

	//}

	//error("bad expression");
}

