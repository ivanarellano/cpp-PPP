#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int fac(int n) {
	int r = 1;

	while (n > 1) {
		r *= n;
		--n;
	}

	return r;
}

double term(double x, int n) { return pow(x, n) / fac(n); }

int main() {
	try {
		using namespace Graph_lib;

		constexpr int xmax = 600;			// window size
		constexpr int ymax = 400;

		constexpr int x_orig = xmax / 2;	// position of (0,0) is center of window
		constexpr int y_orig = ymax / 2;
		constexpr Point orig { x_orig, y_orig };

		constexpr int r_min = -10;			// range [-10:11]
		constexpr int r_max = 11;

		constexpr int n_points = 400;		// number of points used in range

		constexpr int x_scale = 30;			// scaling factors
		constexpr int y_scale = 30;

		Simple_window win = { { 100,100 }, xmax, ymax, "Chapter15" };

		Function s { one, (int) r_min, (int) r_max, orig, n_points, (int) x_scale, (int) y_scale };
		Function s2 { slope, (int) r_min, (int) r_max, orig, n_points, (int) x_scale };	// no y scale
		Function s3 { square, (int) r_min, (int) r_max, orig, n_points };				// no x scale, no y scale
		Function s4 { sqrt, int(r_min), int(r_max), orig };
		Function s5 { cos, int(r_min), int(r_max), orig, 400, 30, 30 };
		Function s6 { [](double x) { return cos(x) + slope(x); }, int(r_min), int(r_max), orig, 400, 30, 30 };

		s.set_color(Color::black);
		s2.set_color(Color::black);
		s3.set_color(Color::black);
		s4.set_color(Color::black);
		s5.set_color(Color::blue);
		s6.set_color(Color::dark_red);

		win.attach(s);
		win.attach(s2);
		win.attach(s3);
		win.attach(s4);
		win.attach(s5);
		win.attach(s6);

		Text ts { Point{100, y_orig - 40}, "one" };
		Text ts2 { Point{100, y_orig + y_orig / 2 - 20}, "x/2" };
		Text ts3 { Point{x_orig - 100, 20}, "x*x" };

		win.set_label("Function graphing: label functions");

		ts.set_color(Color::black);
		ts2.set_color(Color::black);
		ts3.set_color(Color::black);

		win.attach(ts);
		win.attach(ts2);
		win.attach(ts3);

		constexpr int xlength = xmax - 40;	// make the axis a bit smaller than the window
		constexpr int ylength = ymax - 40;

		Axis x { Axis::x, Point{20, y_orig}, xlength, xlength/x_scale, "one notch == 1" };
		Axis y { Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1" };

		x.set_color(Color::red);
		y.set_color(Color::red);

		win.attach(x);
		win.attach(y);

		win.wait_for_button();
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cerr << "exception\n";
		keep_window_open();
	}

	return 0;
}