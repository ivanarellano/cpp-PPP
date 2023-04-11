#include "../std_lib_facilities.h"

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