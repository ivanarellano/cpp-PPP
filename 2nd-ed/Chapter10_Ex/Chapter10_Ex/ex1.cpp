#include "../../../Code Snippets/std_lib_facilities.h"
#include <iostream>
#include <fstream>

//vector<int> getNumbers(std::ifstream& ifs) {
//	vector<int> nums;
//
//	if (!ifs) {
//		std::runtime_error("can't open file");
//	}
//
//	while (true) {
//		int num = 0;
//		if (!(ifs >> num)) break;
//		nums.push_back(num);
//	}
//	return nums;
//}
//
//int getSum(const vector<int>& numbers) {
//	int sum = 0;
//	for (int i : numbers) {
//		sum += i;
//	}
//	return sum;
//}
//
//int main() {
//	std::string file = "ex1.txt";
//	std::ifstream ifs{ file };
//
//	vector<int> nums = getNumbers(ifs);
//
//	int sum = getSum(nums);
//	cout << sum << endl;
//
//	keep_window_open();
//	return 0;
//}