#include "Date.h"

Date::Date(int yy, int mm, int dd) :y { yy }, m { mm }, d { dd } {
	if (!is_valid()) throw Invalid{};
}

Date::~Date() {

}

void Date::add_day(int n) {
	if (n > 0) {
		
	}
}

bool Date::is_valid() {
	if (m < 1 || 12 < m) return false;
}