#pragma once

class Date
{
public:
	Date(int y, int m, int d);
	~Date();
	class Invalid { };
	void add_day(int n);
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
private:
	int y, m, d;
	bool is_valid();
};