// Chapter5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../std_lib_facilities.h"

// converts Celsius to Kelvin
double ctok(double c) {
    double k = c + 273.15;
    return k;
}

/* Original from text:
* double ctok(double c) {
* int k = c + 273.15;
* return int
* }
*/

void e2() {
    /*
    * Original from text:
    * 
    * double c = 0;
    * cin >> d;
    * double k = ctok("c");
    * Cout << k << '/n';
    */
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << k << '\n';
}

void e3() {
    double c = 0;
    cin >> c;
    if (c < 273.15) error("invalid input; absolute zero is -273.15 C");
    double k = ctok(c);
    cout << k << '\n';
}


double ctok_2(double c) {
    if (c < 273.15) error("invalid input; absolute zero is -273.15 C");
    double k = c + 273.15;
    return k;
}

void e4() {
    ctok_2(-300);
}

double ktoc(double k) {
    if (k < 0) error("invalid input; absolute zero is 0 K");
    double c = k - 273.15;
    return c;
}

void e5() {
    double k = 0;
    cin >> k;
    double c = ktoc(k);
    cout << c << '\n';
}

double ctof(double c) {
    if (c < 0) error("invalid input; absolute zero is -273.15 C");
    double f = 9.0 / 5 * c + 32;
    return f;
}

double ftoc(double f) {
    double abs_zero_f = -459.67;
    if (f < abs_zero_f) error("invalid input; absolute zero is " + to_string(abs_zero_f));
    double c = (f - 32) * 5.0 / 9.0;
    return c;
}

void e6() {
    string method;
    double number;
    cout << "Choose first method by typing the number:" << endl;
    cout << "1. celcius to fahrenheit\n";
    cout << "2. fahrenheit to celcius\n";
    cin >> method;
    cout << "Enter first value:\n";
    cin >> number;
    if (method == "1") cout << ctof(number) << endl;
    else if (method == "2") cout << ftoc(number) << endl;
}

void solve_quadratic(double a, double b, double c) {
    if (a == 0) 
        error("first cannot be equal to 0");

    // b2 – 4ac
    double discriminant = b * b - 4 * a * c;
    int roots;
    if (discriminant == 0) {
        roots = 1;
    }
    else if (discriminant > 0) {
        roots = 2;
    }
    else {
        cout << "The quadratic equation has no real roots." << endl; 
        return;
    }
    cout << "Discriminant: " << discriminant << endl;

    double sqrt_term = sqrt(discriminant);
    double root_1, root_2;

    if (1 < roots) {
        root_1 = (-1 * b + sqrt_term) / (2 * a);
        cout << "Root 1: " << root_1 << endl;
    }
    if (roots == 2) {
        root_2 = (-1 * b - sqrt_term) / (2 * a);
        cout << "Root 2: " << root_2 << endl;
    }
}

void e7() {
    solve_quadratic(0, 6, 1);
}

int fibonacci(int first, int second) {
    // This works but it depends on an overflow
    //if (second < 0) return first;
    
    // This is reliable
    if (INT_MAX - second < first) return second;

    if (1 > first) 
        first = 1;
    if (1 > second)
        second = 1;

    int next = first + second;
    return fibonacci(second, next);
}

void e11() {
    int max_int_fib = fibonacci(1, 1);
    cout << "Largest Fibonacci number that fits in an int: " << max_int_fib << endl;
}

void exercises() {
    //e2();
    //e3();
    //e5();
    //e6();
    //e7();
    e11();
}

void d1() {
    //Cout << "Success!\n";
    cout << "Success 1!\n";
}
void d2() {
    //cout << "Success!\n;
    cout << "Success 2!\n";
}
void d3() {
    //cout << "Success" << !\n"
    cout << "Success 3!" << "\n";
}
void d4() {
    //cout << "Success" << !\n"
    cout << "Success 4!" << "\n";
}
void d5() {
    //cout << success << '\n';
    cout << "Success 5!" << '\n';
}
void d6() {
    //string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
    int res = 7; vector<int> v(10); v[5] = res; cout << "Success 6!\n";
}
void d7() {
    //vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n";
    vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success 7!\n";
}
void d8() {
    //if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    bool cond = true;  if (cond) cout << "Success 8!\n"; else cout << "Fail!\n";
}
void d9() {
    //bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    bool c = true; if (c) cout << "Success 9!\n"; else cout << "Fail!\n";
}
void d10() {
    //string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n";
    string s = "ape"; bool c = "ace" < s; if (c) cout << "Success 10!\n";
}
void d11() {
    //string s = "ape"; if (s == "fool") cout << "Success!\n";
    string s = "fool"; if (s == "fool") cout << "Success 11!\n";
}
void d12() {
    //string s = "ape"; if (s + "Fool") cout < "Success!\n";
    string s = "ape"; if (s == "ape") cout << "Success 12!\n";
}
void d13() {
    //vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
    vector<char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success 13!\n";
}
void d14() {
    //vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
    vector<char> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success 14!\n";
}
void d15() {
    //string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
    string s = "Success 15!\n"; for (int i = 0; i < s.size(); ++i) cout << s[i];
}
void d16() {
    //if (true) then cout << "Success!\n"; else cout << "Fail!\n";
    if (true) cout << "Success 16!\n"; else cout << "Fail!\n";
}
void d17() {
    //int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";
    int x = 32; char c = x;
    if (c == 32)
        cout << "Success 17!\n";
}
void d18() {
    //string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];
    string s = "Success 18!\n"; for (int i = 0; i < s.size(); ++i) cout << s[i];

}
void d19() {
    //vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
    vector<int> v(5); for (int i = 0; i < v.size(); ++i); cout << "Success 19!\n";
}
void d20() {
    //int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
    int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success 20!\n";
}
void d21() {
    //int x = 2; double d = 5 / (x - 2); if (d == 2 * x + 0.5) cout << "Success!\n";
    int x = 2; double d = 5.0 / (x - 1);
    if (d == 2 * (x + 0.5))
        cout << "Success 21!\n";
}
void d22() {
    //string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
    string s = "Success 22!\n"; for (int i = 0; i <= 12; ++i) cout << s[i];

}
void d23() {
    //int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
    int i = 0; int j = 0; while (i < 10) ++i; if (j < i) cout << "Success 23!\n";
}
void d24() {
    //int x = 4; double d = 5 / (x - 2); if (d = 2 * x + 0.5) cout << "Success 24!\n";
    int x = 2; double d = 5.0 / (x - 1);
    if (d == 2 * (x + 0.5))
        cout << "Success 24!\n";
}
void d25() {
    //cin << "Success!\n";
    cout << "Success 25!\n";
}

void drills() {
    d1();
    d2();
    d3();
    d4();
    d5();
    d6();
    d7();
    d8();
    d9();
    d10();
    d11();
    d12();
    d13();
    d14();
    d15();
    d16();
    d17();
    d18();
    d19();
    d20();
    d21();
    d22();
    d23();
    d24();
    d25();
}

int main()
{
    try {
        //drills();
        exercises();
        
        keep_window_open();
        return EXIT_SUCCESS;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
