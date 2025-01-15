#include "../shared/headers/PPPheaders.h"

int main()
{
    drill();
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