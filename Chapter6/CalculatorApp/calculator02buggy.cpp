
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

// Annotated version: https://gist.github.com/cortical-iv/4c19719bbce455ec3f2d043fa011d638

#include "stdafx.h"
#include "../../std_lib_facilities.h"

constexpr char ExitChar = 'x';
constexpr char PrintChar = '=';

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case PrintChar:    // for "print"
    case ExitChar:    // for "quit"
    case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

int factorial(int n)
// return n*(n-1)*(n-2)* ... *2
// return 1 if n<1
{
    if (n == 0) return 1;
    int fac = 1;
    while (1 < n) {
        fac *= n;
        --n;
        if (fac < 1) error("factorial overflow");
    }
    return fac;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '{':    // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with !
double factorial_expression()
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '!':
        {
            left = factorial(left);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

// deal with *, /, and %
double term()
{
    double left = factorial_expression();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial_expression(); // 2*4! = 2*(4!)
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial_expression(); // 2/4! = 2/(4!)
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left += term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int e3() {
    cout << "Welcome to our simple calculator." << endl <<
        "Please enter expressions using floating-point numbers." << endl;
    cout << "The available operators are: +, -, *, and /" << endl <<
        "To print the calculation enter \"" << PrintChar <<
        "\". To exit enter \"" << ExitChar << "\"." << endl;
    try
    {
        double val = 0;

        while (cin) {
            Token t = ts.get();

            if (t.kind == ExitChar) break; // 'x' for quit
            if (t.kind == PrintChar)       // '=' for "print now"
                cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
        keep_window_open();
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

//------------------------------------------------------------------------------

int permutations(int a, int b) {
    /*
    * A permutation is an ordered subset of a set. For example, say you wanted to
    * pick a combination to a vault. There are 60 possible numbers, and you need
    * three different numbers for the combinations. There are P(60,3) permutations
    * for the combination.
    */
    return factorial(a) / factorial(a - b);
}

int combinations(int a, int b) {
    /*
    * Combinations are similar to permutations, except that the order of the objects
    * doesn't matter. For example, if you were making a "banana split" sundae and
    * wished to use three different flavors of ice cream out of five that you had,
    * you wouldn't care if you used a scoop of vanilla at the beginning or the end;
    * you would still have used vanilla.
    */
    return permutations(a, b) / factorial(b);
}

int e10() {
    /*
    * Requirements: Calculate permutations for two numbers, calculate combinations 
    * for two numbers, allow the user to input two numbers to use for calculation method
    * Design:
    * Ask to input sequence in the order of 1) method 2) number 3) number
    * Calculate using chosen method and numbers
    */
    int type, a, b;
    cout << "Chose a method number, followed by two numbers. Example: 1 10 2 calculates permutations for 10 and 2\n";
    cout << "Methods\n";
    cout << "1. Calculate permutations\n";
    cout << "2. Calculate combinations\n";
    cin >> type >> a >> b;

    if (type == 1) {
        // Permutations
        cout << "P(" << a << ',' << b << ") = " << permutations(a, b) << endl;
    }
    else if (type == 2) {
        // Combinations
        cout << "C(" << a << ',' << b << ") = " << combinations(a, b) << endl;
    }
    else {
        error("No supported method type found");
    }
    keep_window_open();
    return 0;
}

int main() {
    //return e3();
    return e10();
    return 0;
}
//------------------------------------------------------------------------------
