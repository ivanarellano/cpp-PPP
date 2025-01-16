#include "../shared/headers/PPPheaders.h"

static void exercise_02() {
    // Write a program in C++ that converts from miles to km.
    int miles;
    cout << "Enter the miles to convert to kilometers: ";
    cin >> miles;
    if (miles < 1)
        simple_error("it has to be positive");
    double kilometers = miles * 1.609;
    cout << "\nKilometers: " << kilometers << '\n';
}

static void exercise_04() {
    int val1, val2;
    cout << "Enter the first value, followed by Enter key, then enter the second value" << '\n';
    cin >> val1 >> val2;
    if (val1 == 0 || val2 == 0)
        simple_error("it has to be positive");
    double larger, smaller;
    if (val1 > val2) {
        larger = val1;
        smaller = val2;
    }
    else {
        larger = val2;
        smaller = val1;
    }
    cout << "Larger, smaller: " << larger << ", " << smaller << '\n'
         << "Sum: " << val1 + val2 << '\n'
         << "Difference: " << larger - smaller << '\n'
         << "Product: " << val1 * val2 << '\n'
         << "Ratio: " << smaller / larger << '\n';
}

static void exercise_06() {
    int val1, val2, val3, temp;
    cout << "Enter three integer values" << '\n';
    cin >> val1 >> val2 >> val3;
    if (val1 > val2) {
        temp = val1;
        val1 = val2;
        val2 = temp;
    }
    if (val2 > val3) {
        temp = val2;
        val2 = val3;
        val3 = temp;
    }
    if (val1 > val2) {
        temp = val1;
        val1 = val2;
        val2 = temp;
    }
    cout << val1 << ", " << val2 << ", " << val3 << '\n';
}

static void exercise_07() {
    string val1, val2, val3, temp;
    cout << "Enter three string values" << '\n';
    cin >> val1 >> val2 >> val3;
    if (val1 > val2) {
        temp = val1;
        val1 = val2;
        val2 = temp;
    }
    if (val2 > val3) {
        temp = val2;
        val2 = val3;
        val3 = temp;
    }
    if (val1 > val2) {
        temp = val1;
        val1 = val2;
        val2 = temp;
    }
    cout << val1 << ", " << val2 << ", " << val3 << '\n';
}

static void exercise_08() {
    int val;
    cout << "Enter an integer value" << '\n';
    cin >> val;
    if (val % 2 == 0)
        cout << "The value " << val << " is an even number" << '\n';
    else
        cout << "The value " << val << " is an odd number" << '\n';
}

static void exercise_09() {
    string val;
    cout << "Enter a number from zero to four" << '\n';
    while (cin >> val) {
        if (val == "zero")
            cout << '0' << '\n';
        else if (val == "one")
            cout << '1' << '\n';
        else if (val == "two")
            cout << '2' << '\n';
        else if (val == "three")
            cout << '3' << '\n';
        else if (val == "four")
            cout << '4' << '\n';
        else
            cout << "not a number I know" << '\n';
        cout << "Enter a number from zero to nine" << '\n';
    }
}

static void exercise_10() {
    string operation;
    double operand1, operand2;
    cin >> operation >> operand1 >> operand2;
}

static void drill() {
    string first_name;
    cout << "Enter the name of the person you want to write to" << '\n';
    cin >> first_name;

    string friend_name;
    cout << "Enter the name of another friend" << '\n';
    cin >> friend_name;

    int age;
    cout << "Enter the age of the recipient" << '\n';
    cin >> age;

    cout << "Dear " << first_name << '\n'
        << "    How are you? I am fine. I miss you." << '\n'
        << "I hope you are well. I will see you soon." << '\n'
        << "Have you seen " << friend_name << " lately?" << '\n';
    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");
    else if (age < 12)
        cout << "Next year you will be " << age + 1 << '\n';
    else if (age == 17)
        cout << "Next year you will be able to vote." << '\n';
    else if (age > 70)
        cout << "Are you retired?" << '\n';
    else
        cout << "I hear you just had a birthday and you are " << age << " years old." << '\n';
    cout << "Yours sincerely," << "\n\n" << "Ivan" << '\n';
}

/*
    Input: She she laughed "he he he!" because what he did did not look very very good good.
    Output:
    repeated word: did
    repeated word: very
*/
static void try_this_2_5_1() {
    string previous;
    string current;
    while (cin >> current) {
        if (previous == current)
            cout << "repeated word: " << current << '\n';
        previous = current;
    }
}

int main()
{
    //drill();
    //exercise_02();
    //exercise_04();
    //exercise_06();
    exercise_09();
}