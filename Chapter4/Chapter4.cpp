// Chapter4.cpp : Defines the entry point for the application.
//

#include "Chapter4.h"

void drill() {
	double a = 0, b = 0, sum = 0, value_count = 0;
	double in;
	std::string tmp_unit;
	std::vector<double> all_values;

	constexpr double cm_to_m{ 1 / 100.0 };
	constexpr double in_to_m{ 2.54 * cm_to_m };
	constexpr double ft_to_m{ 12 * in_to_m };

	std::cout << "Enter a value in the format: 12 in. Accepted units are: cm, m, in, ft" << std::endl;
	std::cout << "Enter | to stop counting values" << std::endl;

	while (std::cin >> in >> tmp_unit) {
		if (in <= 0) {
			std::cout << "Please enter a positive number" << std::endl;
			continue;
		}
		if (tmp_unit != "cm" && tmp_unit != "m" && tmp_unit != "in" && tmp_unit != "ft") {
			std::cout << "Invalid unit; Enter a new value" << std::endl;
			continue;
		}

		double converted;

		++value_count;
		if (tmp_unit == "ft") {
			converted = ft_to_m * in;
		}
		else if (tmp_unit == "in") {
			converted = in_to_m * in;
		}
		else if (tmp_unit == "cm") {
			converted = cm_to_m * in;
		}
		else {
			converted = in;
		}

		std::cout << "Converted to meters: " << converted << std::endl;
		all_values.push_back(converted);

		sum += converted;

		if (converted <= b) {
			if (a == 0 || converted <= a) {
				std::cout << "It's the smallest so far" << std::endl;
				a = converted;
			}
		}
		else {
			std::cout << "It's the largest so far" << std::endl;
			b = converted;
		}
	}

	bool areEqual = a == b;
	bool almostEqual = b - a < 1.0 / 100;

	if (areEqual) {
		std::cout << "The numbers are equal" << std::endl;
	}
	else {
		std::cout << "The smaller value is: " << a << std::endl;
		std::cout << "The larger value is: " << b << std::endl;
		if (almostEqual) {
			std::cout << "The numbers are almost equal" << std::endl;
		}
	}

	std::cout << "The sum in meters: " << sum << std::endl;

	std::sort(all_values.begin(), all_values.end());
	for (int i = 0; i < all_values.size(); i++) {
		std::cout << "Values entered: " << all_values[i] << (i == all_values.size() - 1 ? "\n" : ", ");
	}
	std::cout << "Values counted: " << value_count << std::endl;
}

int main()
{
	drill();

	return 0;
}
