// Chapter3.cpp : Defines the entry point for the application.
//

#include "Chapter3.h"

void exercise_six() {
    // prompt the user to enter three integer values
    int a, b, c;
    std::cout << "Enter three numbers" << std::endl;
    std::cin >> a >> b >> c;

    std::vector<int> numbers {a, b, c};
    std::sort(numbers.begin(), numbers.end());

    std::string out;
    for (int i = 0; i < numbers.size(); i++) {
        out += std::to_string(numbers[i]) + (numbers.size() - 1 == i ? "" : ", ");
    }
    std::cout << "Numbers in numerical sequence: " << out << std::endl;
}

void exercise_seven() {
    std::string a, b, c;
    std::cout << "Enter three names" << std::endl;
    std::cin >> a >> b >> c;

    std::vector<std::string> names {a, b, c};
    std::sort(names.begin(), names.end());

    std::string out;
    for (int i = 0; i < names.size(); i++) {
        out += names[i] + (names.size() - 1 == i ? "" : ", ");
    }
    std::cout << "Names in numerical sequence: " << out << std::endl;
}

void exercise_ten() {
    std::string validOps {"+,-,*,/"};
    std::cout << "Enter an operation " << validOps << " followed by two operands, ie + 100 3.14 or * 4 5" << std::endl;
    std::string operation;
    double a, b, out;
    std::cin >> operation >> a >> b;

    if (operation == "+") {
        out = a + b;
    }
    else if (operation == "-") {
        out = a - b;
    }
    else if (operation == "*") {
        out = a * b;
    }
    else if (operation == "/") {
        out = a / b;
    }
    else {
        std::cout << "Not a valid operation from " << validOps << std::endl;
        return;
    }

    std::cout << "Your calculation: " << out << std::endl;
}

int main()
{
    exercise_ten();

    return 0;
}