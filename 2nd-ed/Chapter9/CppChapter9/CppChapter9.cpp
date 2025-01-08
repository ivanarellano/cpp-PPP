#include "../../std_lib_facilities.h"
#include "Date.h"

enum class Month {
	jan=1, feb, mar, apr, may, jun,
	jul, aug, sep, oct, nov, dec
};

enum class Day {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

Month int_to_month(int x) {
	if (x < int(Month::jan) || int(Month::dec) < x) error("bad month");
	return Month(x);
}

Month operator++(Month& m) {
	m = (m == Month::dec) ? Month::jan : Month((int(m) + 1));
	return m;
}

int main()
{
	Month m = int_to_month(2131);

	keep_window_open();
    return 0;
}

