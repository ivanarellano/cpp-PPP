#include <string>


#pragma once
/*
{ year 1990 }
{ year 1991 { month jun } }
{ year 1992 { month jan (1 0 61.5) } { month feb (1 1 64) (2 2 65.2) } }
{ year 2000
	{ month feb (1 1 68) (2 3 66.66) (1 0 67.2) }
	{ month dec (15 15 -9.2) (15 14 -8.8) (14 0 -2) }
*/

const int not_a_reading = -7777;
const int not_a_month = -1;

struct Reading {
	int day;
	int hour;
	double temperature;
};
struct Day {
	std::vector<double> hour { std::vector<double>(24, not_a_reading) };
};
struct Month {
	int month { not_a_month };
	std::vector<Day> day { 32 };
};
struct Year {
	int year;
	std::vector<Month> month { 12 };
};
