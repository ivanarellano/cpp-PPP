#include "Simple_window.h"	// get access to our window library
#include "Graph.h"			// get access to our graphics library facilities

int main() {
	try {
		using namespace Graph_lib;

		Point tl(150, 150);
		Simple_window win(tl, 600, 400, "My window");
		win.resize(600, 400);

		Axis xa { Axis::x, Point{20, 300}, 280, 10, "x axis" };
		xa.set_color(Color::black);
		xa.label.set_color(Color::black);
		win.attach(xa);

		Axis ya { Axis::y, Point{20, 300}, 280, 10, "y axis" };
		ya.set_color(Color::black);
		ya.label.set_color(Color::black);
		win.attach(ya);

		// plot sin() in the range [0:100] with (0,0) at (20,150)
		// using 1000 points; scale x values *50, scale y values *50
		Function sine { sin, 0, 100, Point{20, 150}, 1000, 50, 50 };
		sine.set_color(Color::black);
		win.attach(sine);

		Graph_lib::Polygon poly;
		poly.add(Point{ 300,200 });
		poly.add(Point{ 350, 100 });
		poly.add(Point{ 400,200 });
		poly.set_color(Color::red);
		poly.set_style(Line_style(Line_style::dash,4));
		win.attach(poly);

		Graph_lib::Rectangle r { Point{200,200}, 100, 50 };
		r.set_color(Color::blue);
		r.set_fill_color(Color::yellow);
		win.attach(r);

		Closed_polyline poly_rect;
		poly_rect.add(Point{ 100,50 });
		poly_rect.add(Point{ 200,50 });
		poly_rect.add(Point{ 200,100 });
		poly_rect.add(Point{ 100,100 });
		poly_rect.add(Point{ 50,75 });
		poly_rect.set_color(Color::black);
		poly_rect.set_style(Line_style(Line_style::dash, 2));
		poly_rect.set_fill_color(Color::green);
		win.attach(poly_rect);

		Text t { Point{ 150, 150 }, "Hello, graphical world!" };
		t.set_font(Font::times_bold);
		t.set_font_size(20);
		t.set_color(Color::black);
		win.attach(t);

		Image ii { Point {100, 50}, "image.jpg" };
		ii.move(100, 200);
		win.attach(ii);

		Circle c { Point{100,200}, 50 };
		Graph_lib::Ellipse e { Point{100, 200}, 72, 25 };
		e.set_color(Color::dark_red);
		Mark m{ Point{100, 200}, 'x' };

		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes{ Point{100, 20}, oss.str() };

		Image cal{ Point{225,225}, "snow_cpp.gif" };
		cal.set_mask(Point{ 40,40 }, 200, 150);

		win.attach(c);
		win.attach(m);
		win.attach(e);

		win.attach(sizes);
		win.attach(cal);

		win.wait_for_button();
	}
	catch (exception& e) {
		return 1;
	}

	return 0;
}