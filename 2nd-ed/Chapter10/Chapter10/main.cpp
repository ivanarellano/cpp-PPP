#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Monster.h"

//#include "../../../code_snippets/std_lib_facilities.h"

inline void keep_window_open() {
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
	return;
}

//std::vector<Monster> createMonsters() {
//	Monster m[]{
//		Monster{ "ivan" },
//		Monster{ "mike" },
//		Monster{ "tony" },
//		Monster{ "jordan" }
//	};
//
//	std::vector<Monster> monsters;
//	for each (Monster monster in m) {
//		monsters.push_back(monster);
//	}
//
//	return monsters;
//}

void endOfLoop(std::istream& ist, char term) {
	if (ist.fail()) {
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) {
			return;
		}

		std::runtime_error("some error");
	}
}

/*
read a temperature reading from is into r
format: ( 3 4 9.7)
check format, but don't bother with data validity
*/
std::istream& operator>>(std::istream& is, Reading& r) {
	char ch;
	if (is >> ch && ch != '(') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') {
		std::runtime_error("bad reading");
	}

	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

int monthToInt(std::string month) {
	std::vector<std::string> months{
		"jan", "feb", "mar", "apr", "may",
		"jun", "jul", "aug", "sep", "oct",
		"nov", "dec"
	};

	int i = 0;
	for (std::string m : months) {
		if (m == month) {
			return i;
		}
		++i;
	}

	return -1;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r) {
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature) return false;

	return true;
}

/*
Read a month from is into m
format: { month feb . . . }
*/
std::istream& operator>>(std::istream& is, Month& m) {
	char ch;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::string month_marker;
	std::string mm;
	is >> month_marker >> mm;
	if (!is && month_marker != "month") {
		std::runtime_error("bad start of month");
	}
	m.month = monthToInt(mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading) {
				++duplicates;
			}

			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
		r = Reading{};
	}

	if (invalids) {
		std::runtime_error("invalid readings in month");
	}

	if (duplicates) {
		std::runtime_error("duplicate readings in month");
	}

	endOfLoop(is, '}');
	return is;
}

/*
read a year from is into y
format: { year 1972 ... }
*/
std::istream& operator>>(std::istream& is, Year& y) {
	char ch;
	if (is >> ch && ch != '{') {
		std::runtime_error("bad start of year");
	}

	std::string year_marker;
	int yy;

	is >> year_marker >> yy;
	if (is || year_marker != "year") {
		std::runtime_error("bad start of year");
	}
	y.year = yy;

	while (true) {
		Month m;
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}

	endOfLoop(is, '}');
	return is;
}

int main() {

	////

	//std::vector<Monster> monsters = createMonsters();

	//MonsterParser parser;

	// open an input file
	std::cout << "Please enter input file name:\n";
	std::string iname;
	std::cin >> iname;

	std::ifstream ifs{ iname };

	if (!ifs) {
		std::runtime_error("can't open file");
	}

	// throw for bad()
	ifs.exceptions(ifs.exceptions() | std::ios_base::failbit);

	// open an output file

	//std::vector<Monster> input = parser.parse(iname);
	//for (auto& i : input) {
	//	std::cout << i.name << std::endl;
	//}

	////

	//MonsterWriter writer;

	std::cout << "Please enter name of output file:";
	std::string oname;
	std::cin >> oname;

	std::ofstream ofs{ oname };

	if (!ofs) {
		std::runtime_error("can't open output file");
	}

	std::vector<Year> ys;
	while (true) {
		Year y;
		if (!(ifs >> y)) break;
		ys.push_back(y);
	}

	//writer.write(monsters, oname);

	////

 	keep_window_open();
	return 0;
}